#ifndef VISUALIZER_H
#define VISUALIZER_H
#include "MemoryBlock.h"
#include <list>

class Visualizer {
public:
    static void drawMemoryMap(const std::list<MemoryBlock>& memoryPool, size_t totalSize);
};

#endif