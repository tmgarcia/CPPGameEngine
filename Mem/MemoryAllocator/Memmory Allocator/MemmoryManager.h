#pragma once
#include "MemBlockInfo.h"
#include <stdlib.h>
using namespace std;

class MemmoryManager
{
public:
	void initialize();
	void shutDown();
	static void* theRam;
	static MemBlockInfo* meHead;
};

void *operator new(size_t size);
void operator delete(void *victim);
