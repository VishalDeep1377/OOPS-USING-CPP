#include "Scheduler.h"
#include <iostream>
#include <vector>
#include <algorithm>

void Scheduler::suggestOptimalSchedule(const Planner& planner) {
    std::vector<Task*> pendingTasks;
    for (Task* t : planner.getTasks()) {
        if (!t->isCompleted()) pendingTasks.push_back(t);
    }

    // STL Algorithms leveraging custom operator< inside Task
    std::sort(pendingTasks.begin(), pendingTasks.end(), [](Task* a, Task* b) {
        return *a < *b; 
    });

    std::cout << "\n--- Optimal Schedule for Today ---\n";
    int slots = std::min(5, (int)pendingTasks.size());
    for (int i = 0; i < slots; ++i) {
        std::cout << "Slot " << i+1 << ": " << pendingTasks[i]->getTitle() 
                  << " (Priority: " << pendingTasks[i]->calculatePriority() << ")\n";
    }
    if (pendingTasks.size() > 5) {
        std::cout << "* " << pendingTasks.size() - 5 
                  << " more tasks pushed to later to prevent overload.\n";
    }
}