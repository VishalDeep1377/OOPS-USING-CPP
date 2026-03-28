#ifndef ALLOCATOR_H
#define ALLOCATOR_H
#include "MemoryBlock.h"
#include <list>

// Abstract Base Class
class Allocator {
public:
    virtual ~Allocator() {}
    // Pure virtual function resolving dynamically at runtime
    virtual bool allocate(std::list<MemoryBlock>& memoryPool, int pid, size_t requestedSize) = 0;
};

class FirstFit : public Allocator {
public:
    bool allocate(std::list<MemoryBlock>& memoryPool, int pid, size_t requestedSize) override;
};

class BestFit : public Allocator {
public:
    bool allocate(std::list<MemoryBlock>& memoryPool, int pid, size_t requestedSize) override;
};

class WorstFit : public Allocator {
public:
    bool allocate(std::list<MemoryBlock>& memoryPool, int pid, size_t requestedSize) override;
};
#endif