// Copyright 2015 A.Bekkine

#include "Timer.h"

Timer::Timer() {
    minimum_period_ = 0.0;

    // TODO(abekkine) : CTOR
}

Timer::~Timer() {
    // TODO(abekkine) : DTOR
}

void Timer::SetHandler(void (*handler)()) {
    // TODO(abekkine) : Set handler callback from TaskManager.
    handler = handler;
}

void Timer::SetMinimumPeriod(double minimum_period) {
    // Set minimum period value for setting up timer.
    minimum_period_ = minimum_period;
}

void Timer::Initialize() {
    // TODO(abekkine) : Initialization; setup original signal handler, etc.
}

