// Copyright 2015 A.Bekkine

#ifndef TASK_H
#define TASK_H

class Task {
 public:
    void Frequency(double frequency);
    // TODO(abekkine) : Will be made virtual later.
    void Initialize();

 public:
    static void TimeResolution(double resolution);

 private:
    double frequency_;
    static double resolution_;
};

#endif  // TASK_H

