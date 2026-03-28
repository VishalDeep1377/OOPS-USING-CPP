#ifndef SCHEDULER_H
#define SCHEDULER_H
#include "Planner.h"

class Scheduler {
public:
    static void suggestOptimalSchedule(const Planner& planner);
};
#endif