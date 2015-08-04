// Copyright 2015 A.Bekkine

#include "Task.h"

double Task::resolution_ = 0.0;

void Task::TimeResolution(double resolution) {
    resolution_ = resolution;
}

void Task::Frequency(double frequency) {
    frequency_ = frequency;
}

void Task::Initialize() {
    // TODO(abekkine) : Will be defined in sub-classes later.
}
