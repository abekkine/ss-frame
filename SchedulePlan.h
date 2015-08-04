// Copyright 2015 A.Bekkine

#ifndef SCHEDULE_PLAN_
#define SCHEDULE_PLAN_

#include <vector>

class SchedulePlan {
 public:
    SchedulePlan(int maximum_frequency);
    ~SchedulePlan();
    void Calculate(std::vector<double> & frequencies);

 public:
    // Calculated schedule plan parameters.
    int maximum_ticks;
    double minimum_period;

 private:
    int maximum_frequency_;
};

#endif  // SCHEDULE_PLAN_
