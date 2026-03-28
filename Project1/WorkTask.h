#ifndef WORKTASK_H
#define WORKTASK_H
#include "Task.h"

class WorkTask : public Task {
public:
    WorkTask(std::string t, std::string d, int dtd) : Task(t, d, dtd, "Work") {}
    int calculatePriority() const override {
        if (daysToDeadline <= 2) return 90;
        if (daysToDeadline <= 7) return 70;
        return 50;
    }
};
#endif