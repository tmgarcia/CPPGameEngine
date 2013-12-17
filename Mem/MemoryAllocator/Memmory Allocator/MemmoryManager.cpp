#include "MemmoryManager.h"

void* MemmoryManager::theRam = nullptr;
MemBlockInfo* MemmoryManager::meHead = nullptr;

void MemmoryManager::initialize()
{
	MemmoryManager::theRam = malloc(32);
	MemmoryManager::meHead = reinterpret_cast<MemBlockInfo*>(theRam);
	MemmoryManager::meHead->blockSize = 32;
	MemmoryManager::meHead->nextBlock = 0;
}

void MemmoryManager::shutDown()
{
	free(theRam);
}

void* operator new(size_t size)
{
	MemBlockInfo* runner = MemmoryManager::meHead;
	size_t neededSpace = sizeof(size_t)+size;
	while(runner)
	{
		if(neededSpace <=runner->blockSize)
			break;
		runner = runner->nextBlock;
	}
	if(runner==0)
		return 0;
	char* ret = reinterpret_cast<char*>(runner);
	size_t remainingSpace = runner->blockSize - neededSpace;
	runner->blockSize = neededSpace;

	if(sizeof(MemBlockInfo) <= remainingSpace)
	{
		MemBlockInfo* newBlock = reinterpret_cast<MemBlockInfo*>(ret + neededSpace);
		newBlock->blockSize = remainingSpace;
		newBlock->nextBlock = runner->nextBlock;
		if(runner = MemmoryManager::meHead)
			MemmoryManager::meHead = newBlock;
	}
	else
	{
		if(runner == MemmoryManager::meHead)
		{
			MemmoryManager::meHead = runner->nextBlock;
		}
	}

	return ret + sizeof(size_t);
}

void operator delete(void* victim)
{
	MemBlockInfo* theChain = MemmoryManager::meHead;
	char* temp = reinterpret_cast<char*>(victim) - sizeof(size_t);
	MemmoryManager::meHead = reinterpret_cast<MemBlockInfo*>(temp);
	MemmoryManager::meHead->nextBlock = theChain;
}

