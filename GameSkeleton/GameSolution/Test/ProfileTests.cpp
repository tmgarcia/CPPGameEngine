#include <gtest\gtest.h>
#include "Profiler.h"
#include <iostream>
#include <fstream>
using std::ifstream;
using std::string;

namespace
{
	char *categories[] =
	{
		"Category1",
		"Category2",
		"Category3",
	};

	const char* const PROFILE_FILE_NAME = "profiles.csv";
	const unsigned int NUM_CATEGORIES = sizeof(categories) / sizeof(*categories);

	string getNextToken(ifstream& theFile)
	{
		char c;
		string ret;
		while(theFile.good())
		{
			theFile >> std::noskipws;
			theFile >> c;
			if(c == ',' || c == '\n')
			{
				break;
			}
			ret += c;
		}
		return ret;
	}

	bool isAtEndOfFile(ifstream& input)
	{
		if(!input.good())
		{
			return false;
		}
		char bitBucket;
		input >> bitBucket;
		return !input.good();
	}

	void writeFrames(unsigned int numFrames)
	{
		float sampleNumber = 0;
		for(float frame = 0; frame < numFrames; frame++)
		{
			profiler.newFrame();

			for(unsigned int cat = 0; cat < NUM_CATEGORIES; cat++)
			{
				profiler.addEntry(categories[cat], sampleNumber++);
			}
		}
	}

	void checkFrames(unsigned int numFrames, bool excludeLastFrame = false)
	{
		ifstream input(PROFILE_FILE_NAME);

		for(unsigned int i = 0; i < NUM_CATEGORIES; i++)
		{
			EXPECT_EQ(getNextToken(input), categories[i]);
		}
		
		unsigned int profileNumber = 0;
		if(numFrames >= Profiler::MAX_FRAME_SAMPLES)
		{
			profileNumber = (numFrames - Profiler::MAX_FRAME_SAMPLES) * NUM_CATEGORIES;
			numFrames = Profiler::MAX_FRAME_SAMPLES;
		}

		if(excludeLastFrame)
		{
			profileNumber += NUM_CATEGORIES;
			numFrames--;
		}

		for(unsigned int i = 0; i < (numFrames * NUM_CATEGORIES); i++)
		{
			string buf = getNextToken(input);
			EXPECT_EQ(atoi(buf.c_str()), profileNumber++);
		}
		EXPECT_TRUE(isAtEndOfFile(input));
	}
	
	void runTestsOnFrames(unsigned int numFrames)
	{
		profiler.initialize(PROFILE_FILE_NAME);
		writeFrames(numFrames);
		profiler.shutdown();
		checkFrames(numFrames);
	}

	TEST(Profiler, SmallAmountOfFrames)
	{
		runTestsOnFrames(4);
	}

	TEST(Profile, LargeAmountOfFramesNonCircular)
	{
		const unsigned int NUM_FRAMES_THIS_TEST = 
			static_cast<unsigned int>(Profiler::MAX_FRAME_SAMPLES * .8);
		runTestsOnFrames(NUM_FRAMES_THIS_TEST);
	}

	TEST(Profile, ArrayBoundaries)
	{
		runTestsOnFrames(Profiler::MAX_FRAME_SAMPLES);
		runTestsOnFrames(Profiler::MAX_FRAME_SAMPLES + 1);
		runTestsOnFrames(Profiler::MAX_FRAME_SAMPLES + 2);
	}

	TEST(Profile, CirculatingOncePlusSome)
	{
		const unsigned int NUM_FRAMES_THIS_TEST = 
			static_cast<unsigned int>(Profiler::MAX_FRAME_SAMPLES * 3);
		runTestsOnFrames(NUM_FRAMES_THIS_TEST);
	}

	TEST(Profile, CirculatingMoreThanOnce)
	{
		const unsigned int NUM_FRAMES_THIS_TEST = 
			static_cast<unsigned int>(Profiler::MAX_FRAME_SAMPLES * 3.14);
		runTestsOnFrames(NUM_FRAMES_THIS_TEST);
	}

	void writeIncompleteFrames(unsigned int numFrames)
	{
		bool wrapped = numFrames >= Profiler::MAX_FRAME_SAMPLES;
		profiler.initialize(PROFILE_FILE_NAME);
		writeFrames(numFrames);
		profiler.newFrame();
		profiler.addEntry(categories[0], 99);
		profiler.shutdown();
		checkFrames(numFrames, wrapped);

		profiler.initialize(PROFILE_FILE_NAME);
		writeFrames(numFrames);
		profiler.newFrame();
		profiler.addEntry(categories[0], 100);
		profiler.addEntry(categories[1], 101);
		profiler.shutdown();
		checkFrames(numFrames, wrapped);
	}

	TEST(Profiler, ExcludeIncompleteFrames)
	{
		assert(Profiler::MAX_FRAME_SAMPLES > 2 && "ProfileTest only supports a profiler with a MAX_FRAME_SAMPLES of greater than 2.");
		writeIncompleteFrames(Profiler::MAX_FRAME_SAMPLES - 2); // non-wrapping
		writeIncompleteFrames(Profiler::MAX_FRAME_SAMPLES + 2); // wrapping
	}
}