#ifndef GARBAGECOLLECTOR_H
#define GARBAGECOLLECTOR_H
#include "MemoryBlock.h"
#include <list>

class GarbageCollector {
public:
    static int mergeFreeBlocks(std::list<MemoryBlock>& memoryPool);
};

#endif