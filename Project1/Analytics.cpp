#include "Analytics.h"
#include <iostream>

void Analytics::generateReport(const Planner& planner) {
    // Notice access to planner.tasks! Enabled by friend class keyword inside Planner.
    const auto& tasks = planner.tasks; 
    int completed = 0;
    int total = tasks.size();

    for (const Task* t : tasks) {
        if (t->isCompleted()) completed++;
    }

    int score = total == 0 ? 0 : (completed * 100) / total;
    std::cout << "\n--- Analytics Report ---\n"
              << "Total Tasks: " << total << "\n"
              << "Completed Tasks: " << completed << "\n"
              << "Productivity Score: " << score << "/100\n";
}