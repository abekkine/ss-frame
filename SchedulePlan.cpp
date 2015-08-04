// Copyright 2015 A.Bekkine
#include <vector>

#include "SchedulePlan.h"

SchedulePlan::SchedulePlan(int maximum_frequency)
: maximum_frequency_(maximum_frequency) {
    maximum_ticks = -1;
    minimum_period = 0.0;
}

SchedulePlan::~SchedulePlan() {
    // TODO(abekkine) : DTOR
}

void SchedulePlan::Calculate(std::vector< double > & frequencies) {
    // TODO(abekkine) : Calculate plan.
    frequencies.pop_back();
}
