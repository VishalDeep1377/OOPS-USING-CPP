/*
 * Project: OS Memory Simulator & GC
 * Demonstrates: Dynamic Pointer Tracking, Abstraction, Polymorphism, Hardware-level Logic
 */
#include "MemoryManager.h"
#include "Allocator.h"
#include <iostream>
#include <string>

void displayMenu() {
    std::cout << "\n================================\n"
              << " MEMORY OS SIMULATOR KERNEL v1.0\n"
              << "================================\n"
              << "1. Allocate Memory (Spawn Process)\n"
              << "2. Deallocate Memory (Kill Process)\n"
              << "3. Run Garbage Collector (Defragment)\n"
              << "4. Show System Memory Map\n"
              << "5. Run Leak Detector\n"
              << "6. Change Allocation Algorithm\n"
              << "7. Shutdown System\n"
              << "Input: ";
}

int main() {
    // Simulate 1024 bytes (1 KB) of RAM
    MemoryManager os(1024);
    os.setAllocator(new FirstFit()); // Default to FirstFit algorithm

    int choice = 0, pidCounter = 1;
    while (choice != 7) {
        displayMenu();
        std::cin >> choice;

        switch(choice) {
            case 1: {
                size_t size; std::string name;
                std::cout << "Enter Process Name: "; std::cin >> name;
                std::cout << "Enter memory required (bytes): "; std::cin >> size;
                os.createProcess(pidCounter++, name, size);
                break;
            }
            case 2: {
                int targetPid; std::cout << "Enter PID to kill: "; std::cin >> targetPid;
                os.killProcess(targetPid);
                break;
            }
            case 3: os.runGarbageCollector(); break;
            case 4: os.showMemoryMap(); break;
            case 5: os.checkLeaks(); break;
            case 6: {
                int algo; std::cout << "1. FirstFit  2. BestFit  3. WorstFit: "; std::cin >> algo;
                if (algo == 1) os.setAllocator(new FirstFit());
                else if (algo == 2) os.setAllocator(new BestFit());
                else if (algo == 3) os.setAllocator(new WorstFit());
                break;
            }
        }
    }
    return 0;
}