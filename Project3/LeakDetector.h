#ifndef LEAKDETECTOR_H
#define LEAKDETECTOR_H
#include <cstddef>

class LeakDetector {
private:
    static size_t totalAllocated;
    static size_t totalFreed;
public:
    static void recordAllocation(size_t size);
    static void recordFree(size_t size);
    static void reportLeaks();
    static size_t getActiveMemory();
};

#endif