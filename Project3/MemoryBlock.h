#ifndef MEMORYBLOCK_H
#define MEMORYBLOCK_H
#include <cstddef>

struct MemoryBlock {
    size_t offset;
    size_t size;
    bool isFree;
    int processID; // -1 if free

    MemoryBlock(size_t off, size_t sz, bool freeStat = true, int pid = -1)
        : offset(off), size(sz), isFree(freeStat), processID(pid) {}
};

#endif