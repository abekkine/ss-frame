// Copyright 2015 A.Bekkine
#include <stdio.h>
#include <vector>

#include "SchedulePlan.h"

SchedulePlan::SchedulePlan(int maximum_frequency)
: maximum_frequency_(maximum_frequency) {
    maximum_ticks = -1;
    minimum_period = 0.0;
}

SchedulePlan::~SchedulePlan() {
}

int SchedulePlan::GCD(const std::vector< int >& numbers) {
    // Greatest common divisor of a number array.
    std::vector< int > numbers_ = numbers;
    int gcd;

    gcd = numbers_.back();
    numbers_.pop_back();

    while (!numbers_.empty()) {
        gcd = GCD(gcd, numbers_.back());
        numbers_.pop_back();
    }

    return gcd;
}

int SchedulePlan::GCD(const int a, const int b) {
    // Greatest common divisor of two numbers.
    int a_ = a, b_ = b;

    while (b_ != 0) {
        int t_ = b_;
        b_ = a_ % b_;
        a_ = t_;
    }

    return a_;
}

int SchedulePlan::LCM(const std::vector< int >& numbers) {
    // Least common multiple of a number array.
    std::vector< int > numbers_ = numbers;
    int lcm;

    lcm = numbers_.back();
    numbers_.pop_back();

    while (!numbers_.empty()) {
        lcm = LCM(lcm, numbers_.back());
        numbers_.pop_back();
    }

    return lcm;
}

int SchedulePlan::LCM(const int a, const int b) {
    // Least common multiple of two numbers.
    return a * b / GCD(a, b);
}

void SchedulePlan::Calculate(std::vector< double > & frequencies) {
    // Calculate plan.
    std::vector< double >::iterator iter;
    double minimum_allowed_period = 1.0 / maximum_frequency_;
    std::vector< int > ticks;
    int major_frame;
    int minor_frame;

    for (iter = frequencies.begin(); iter != frequencies.end(); ++iter) {
        ticks.push_back(1.0 / ((*iter) * minimum_allowed_period));
    }

    major_frame = LCM(ticks);
    minor_frame = GCD(ticks);

    maximum_ticks = major_frame / minor_frame;
    minimum_period = minimum_allowed_period * minor_frame;
}
