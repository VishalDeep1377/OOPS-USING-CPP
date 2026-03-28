#ifndef PERSONALTASK_H
#define PERSONALTASK_H
#include "Task.h"

class PersonalTask : public Task {
public:
    PersonalTask(std::string t, std::string d, int dtd) : Task(t, d, dtd, "Personal") {}
    int calculatePriority() const override {
        return (daysToDeadline <= 1) ? 60 : 20;
    }
};
#endif