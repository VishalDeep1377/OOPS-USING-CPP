#include "Visualizer.h"
#include <iostream>
#include <iomanip>

void Visualizer::drawMemoryMap(const std::list<MemoryBlock>& memoryPool, size_t totalSize) {
    std::cout << "\n\033[36m=== SYSTEM MEMORY MAP ===\033[0m\n";
    std::cout << "|";
    
    size_t displayScale = totalSize / 50; // Max 50 blocks width visual
    if (displayScale == 0) displayScale = 1;

    for (const auto& block : memoryPool) {
        int visualWidth = std::max(1, (int)(block.size / displayScale));
        
        if (block.isFree) {
            std::cout << "\033[32m"; // Green for free
            for (int i=0; i < visualWidth; ++i) std::cout << ".";
            std::cout << "\033[0m|";
        } else {
            std::cout << "\033[31m"; // Red for allocated
            std::cout << "P" << block.processID;
            for (int i=0; i < visualWidth - 1; ++i) std::cout << "#";
            std::cout << "\033[0m|";
        }
    }
    std::cout << "\n";
    std::cout << "Legend: [\033[32m....\033[0m] Free Space | [\033[31mP1##\033[0m] Allocated to Process\n";
}