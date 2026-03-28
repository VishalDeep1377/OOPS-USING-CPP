#include "Planner.h"
#include <iostream>

Planner::~Planner() {
    for (Task* t : tasks) {
        delete t; // Proper dynamic memory (new/delete) management
    }
    tasks.clear();
}

void Planner::addTask(Task* task) {
    tasks.push_back(task);
    std::cout << "Task '" << task->getTitle() << "' added successfully!\n";
}

void Planner::viewTasks() const { // Const Correctness
    std::cout << "\n--- Your Tasks ---\n";
    if (tasks.empty()) std::cout << "No tasks found.\n";
    for (const Task* t : tasks) {
        t->display(); // Polymorphic behavior resolving at runtime
    }
}

void Planner::completeTask(int id) {
    for (Task* t : tasks) {
        if (t->getId() == id) {
            t->markCompleted();
            std::cout << "Task ID " << id << " marked as completed!\n";
            return;
        }
    }
    std::cout << "Error: Task ID not found.\n";
}

const std::vector<Task*>& Planner::getTasks() const {
    return tasks;
}