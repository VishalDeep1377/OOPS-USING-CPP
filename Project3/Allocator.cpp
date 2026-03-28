#include "Allocator.h"
#include <iterator>

bool splitBlock(std::list<MemoryBlock>& pool, std::list<MemoryBlock>::iterator it, int pid, size_t size) {
    if (it->size > size) {
        // Insert new free block right after the allocated one
        MemoryBlock freeBlock(it->offset + size, it->size - size, true, -1);
        pool.insert(std::next(it), freeBlock);
    }
    it->size = size;
    it->isFree = false;
    it->processID = pid;
    return true;
}

bool FirstFit::allocate(std::list<MemoryBlock>& memoryPool, int pid, size_t requestedSize) {
    for (auto it = memoryPool.begin(); it != memoryPool.end(); ++it) {
        if (it->isFree && it->size >= requestedSize) {
            return splitBlock(memoryPool, it, pid, requestedSize);
        }
    }
    return false;
}

bool BestFit::allocate(std::list<MemoryBlock>& memoryPool, int pid, size_t requestedSize) {
    auto bestFit = memoryPool.end();
    size_t minDiff = static_cast<size_t>(-1); // Max size_t

    for (auto it = memoryPool.begin(); it != memoryPool.end(); ++it) {
        if (it->isFree && it->size >= requestedSize) {
            size_t diff = it->size - requestedSize;
            if (diff < minDiff) {
                minDiff = diff;
                bestFit = it;
            }
        }
    }

    if (bestFit != memoryPool.end()) {
        return splitBlock(memoryPool, bestFit, pid, requestedSize);
    }
    return false;
}

bool WorstFit::allocate(std::list<MemoryBlock>& memoryPool, int pid, size_t requestedSize) {
    auto worstFit = memoryPool.end();
    size_t maxDiff = 0;

    for (auto it = memoryPool.begin(); it != memoryPool.end(); ++it) {
        if (it->isFree && it->size >= requestedSize) {
            size_t diff = it->size - requestedSize;
            if (worstFit == memoryPool.end() || diff > maxDiff) {
                maxDiff = diff;
                worstFit = it;
            }
        }
    }

    if (worstFit != memoryPool.end()) {
        return splitBlock(memoryPool, worstFit, pid, requestedSize);
    }
    return false;
}