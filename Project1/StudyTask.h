#ifndef STUDYTASK_H
#define STUDYTASK_H
#include "Task.h"

class StudyTask : public Task {
public:
    StudyTask(std::string t, std::string d, int dtd) : Task(t, d, dtd, "Study") {}
    int calculatePriority() const override {
        if (daysToDeadline <= 1) return 100; // Crunch time
        if (daysToDeadline <= 5) return 80;
        return 40;
    }
};
#endif