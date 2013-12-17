#include <stdlib.h>
#include "MemBlockInfo.h"
#include "MemmoryManager.h"
using namespace std;


void main()
{
	MemmoryManager newMem;
	newMem.initialize();
	int* p1 = new int;
	*p1 = 1;
	int* p2 = new int;
	*p2 = 2;
	int* p3 = new int;
	*p3 = 3;
	delete p1;
	delete p3;
	int* p4 = new int;
	*p4 = 4;
	delete p2;
	delete p4;
	int* p5 = new int;
	*p5 = 5;
	int* p6 = new int;
	*p6 = 6;
	delete p6;
	newMem.shutDown();
}