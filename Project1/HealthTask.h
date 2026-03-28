#ifndef HEALTHTASK_H
#define HEALTHTASK_H
#include "Task.h"

class HealthTask : public Task {
public:
    HealthTask(std::string t, std::string d, int dtd) : Task(t, d, dtd, "Health") {}
    int calculatePriority() const override {
        // Health tasks maintain a consistently high priority
        if (daysToDeadline <= 1) return 95;
        return 75;
    }
};
#endif