#ifndef DEBUG_PROFILER_H
#define DEBUG_PROFILER_H



class Profiler
{
public: 
	static const unsigned int MAX_FRAME_SAMPLES = 5;
private:
	const char* filename;
	static const unsigned int MAX_PROFILE_CATEGORIES = 20;
	signed int frameIndex;
	unsigned int categoryIndex;
	unsigned int numUsedCategories;
	struct ProfileCategory
	{
		const char* name;
		float samples[MAX_FRAME_SAMPLES];
	} categories[MAX_PROFILE_CATEGORIES];
	void writeFrame(unsigned int frameNumber) const;
	void writeData() const;
	char getDelimiter(unsigned int index) const;
	bool wrapped() const;
	bool currentFrameComplete() const;
public:
	void initialize(const char* filename);
	void shutdown();
	void addEntry(const char* category, float time);
	void newFrame();
};

#endif