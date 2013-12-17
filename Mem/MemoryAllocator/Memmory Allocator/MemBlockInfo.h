#pragma once

struct MemBlockInfo
{
	size_t blockSize;
	MemBlockInfo* nextBlock;
};