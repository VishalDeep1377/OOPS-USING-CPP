#include "GarbageCollector.h"

int GarbageCollector::mergeFreeBlocks(std::list<MemoryBlock>& memoryPool) {
    int mergedCount = 0;
    auto it = memoryPool.begin();
    
    while (it != memoryPool.end() && std::next(it) != memoryPool.end()) {
        auto nextIt = std::next(it);
        if (it->isFree && nextIt->isFree) {
            it->size += nextIt->size;
            memoryPool.erase(nextIt);
            mergedCount++;
        } else {
            ++it;
        }
    }
    return mergedCount;
}