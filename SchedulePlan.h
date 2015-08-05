// Copyright 2015 A.Bekkine

#ifndef SCHEDULE_PLAN_
#define SCHEDULE_PLAN_

#include <vector>

class SchedulePlan {
 public:
    SchedulePlan(int maximum_frequency);
    ~SchedulePlan();
    void Calculate(std::vector<double> & frequencies);

 private:
    int GCD(const std::vector< int >& numbers);
    int GCD(const int a, const int b);
    int LCM(const std::vector< int >& numbers);
    int LCM(const int a, const int b);

 public:
    // Calculated schedule plan parameters.
    int maximum_ticks;
    double minimum_period;

 private:
    int maximum_frequency_;
};

#endif  // SCHEDULE_PLAN_
