#ifndef MEMORYMANAGER_H
#define MEMORYMANAGER_H
#include "MemoryBlock.h"
#include "Allocator.h"
#include "Process.h"
#include <list>
#include <vector>

class MemoryManager {
private:
    size_t totalMemory;
    char* physicalMemory; // Actual dynamic heap memory managed by simulator!
    std::list<MemoryBlock> memoryPool;
    std::vector<Process*> activeProcesses;
    Allocator* currentAllocator;

public:
    MemoryManager(size_t size);
    ~MemoryManager();

    void setAllocator(Allocator* allocator);
    void createProcess(int pid, std::string name, size_t size);
    void killProcess(int pid);
    
    void runGarbageCollector();
    void showMemoryMap() const;
    void checkLeaks() const;
};

#endif