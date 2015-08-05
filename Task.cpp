// Copyright 2015 A.Bekkine

#include <stdio.h>

#include "Task.h"

double Task::resolution_ = 0.0;

void Task::TimeResolution(double resolution) {
    resolution_ = resolution;
}

void Task::Frequency(double frequency) {
    frequency_ = frequency;
}

void Task::SetupScheduling() {
    frame_modus_ = 1.0 / (frequency_ * resolution_);
    task_counter_ = 0;
}

bool Task::OnTime() {
    bool canRunIt = false;

    if (task_counter_ % frame_modus_ == 0) {
        canRunIt = true;
        task_counter_ = 0;
    }

    task_counter_++;

    return canRunIt;
}
