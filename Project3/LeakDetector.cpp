#include "LeakDetector.h"
#include "Logger.h"
#include <iostream>

size_t LeakDetector::totalAllocated = 0;
size_t LeakDetector::totalFreed = 0;

void LeakDetector::recordAllocation(size_t size) { totalAllocated += size; }
void LeakDetector::recordFree(size_t size) { totalFreed += size; }
size_t LeakDetector::getActiveMemory() { return totalAllocated - totalFreed; }

void LeakDetector::reportLeaks() {
    std::cout << "\n--- Memory Leak Analysis ---\n";
    std::cout << "Total Allocated: " << totalAllocated << " bytes\n";
    std::cout << "Total Freed:     " << totalFreed << " bytes\n";
    size_t leaked = totalAllocated - totalFreed;
    if (leaked == 0) {
        Logger::success("No memory leaks detected. System is clean.");
    } else {
        Logger::error("MEMORY LEAK DETECTED: " + std::to_string(leaked) + " bytes lost in the void!");
    }
}