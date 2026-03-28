#include "MemoryManager.h"
#include "GarbageCollector.h"
#include "Visualizer.h"
#include "LeakDetector.h"
#include "Logger.h"
#include <iostream>
#include <algorithm>

MemoryManager::MemoryManager(size_t size) : totalMemory(size) {
    // System Level: Allocating actual heap RAM for the simulator
    physicalMemory = new char[totalMemory];
    LeakDetector::recordAllocation(totalMemory);
    
    // Initialize single large free block
    memoryPool.push_back(MemoryBlock(0, totalMemory, true, -1));
    currentAllocator = nullptr;
    Logger::success("Memory Manager Initialized. " + std::to_string(totalMemory) + " bytes allocated.");
}

MemoryManager::~MemoryManager() {
    // Clean up simulated physical memory
    delete[] physicalMemory;
    LeakDetector::recordFree(totalMemory);
    
    for (Process* p : activeProcesses) {
        delete p;
    }
    if (currentAllocator) delete currentAllocator;
}

void MemoryManager::setAllocator(Allocator* allocator) {
    if (currentAllocator) delete currentAllocator;
    currentAllocator = allocator;
}

void MemoryManager::createProcess(int pid, std::string name, size_t size) {
    if (!currentAllocator) {
        Logger::error("No allocation algorithm selected!");
        return;
    }
    
    if (currentAllocator->allocate(memoryPool, pid, size)) {
        Process* newProc = new Process(pid, name, size);
        activeProcesses.push_back(newProc);
        // We simulate process data being leaked if it's not freed properly
        LeakDetector::recordAllocation(size); 
        Logger::log("Process " + std::to_string(pid) + " (" + name + ") allocated " + std::to_string(size) + " bytes.");
    } else {
        Logger::warning("Memory allocation failed for Process " + std::to_string(pid) + ". Fragmentation or Insufficient Space.");
    }
}

void MemoryManager::killProcess(int pid) {
    auto it = std::remove_if(activeProcesses.begin(), activeProcesses.end(), 
                             [pid](Process* p) { return p->getPid() == pid; });
                             
    if (it != activeProcesses.end()) {
        size_t freedBytes = (*it)->getMemorySize();
        LeakDetector::recordFree(freedBytes);
        delete *it;
        activeProcesses.erase(it, activeProcesses.end());

        // Mark blocks as free
        for (auto& block : memoryPool) {
            if (block.processID == pid) {
                block.isFree = true;
                block.processID = -1;
            }
        }
        Logger::success("Process " + std::to_string(pid) + " killed. Memory freed.");
    } else {
        Logger::error("Process ID " + std::to_string(pid) + " not found.");
    }
}

void MemoryManager::runGarbageCollector() {
    int merged = GarbageCollector::mergeFreeBlocks(memoryPool);
    Logger::log("Garbage Collector ran. " + std::to_string(merged) + " adjacent blocks coalesced.");
}

void MemoryManager::showMemoryMap() const {
    Visualizer::drawMemoryMap(memoryPool, totalMemory);
}

void MemoryManager::checkLeaks() const { LeakDetector::reportLeaks(); }