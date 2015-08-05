// Copyright 2015 A.Bekkine

#ifndef TASK_H
#define TASK_H

class Task {
 public:
    virtual void Step() = 0;
    virtual void Initialize() = 0;

 public:
    void Frequency(double frequency);
    bool OnTime();
    void SetupScheduling();

 public:
    static void TimeResolution(double resolution);

 private:
    double frequency_;
    static double resolution_;
    int task_counter_;
    int frame_modus_;
};

#endif  // TASK_H

