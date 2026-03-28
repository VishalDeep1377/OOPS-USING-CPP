#ifndef PLANNER_H
#define PLANNER_H
#include "Task.h"
#include <vector>

class Planner {
private:
    std::vector<Task*> tasks;
    friend class Analytics; // Advanced feature: Friend class
public:
    ~Planner();
    void addTask(Task* task);
    void viewTasks() const;
    void completeTask(int id);
    const std::vector<Task*>& getTasks() const;
};
#endif