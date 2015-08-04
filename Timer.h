// Copyright 2015 A.Bekkine

#ifndef TIMER_H_
#define TIMER_H_

class Timer {
 public:
    Timer();
    ~Timer();
    void SetHandler(void (*handler)());
    void SetMinimumPeriod(double minimum_period);
    void Initialize();
    void Start();

 private:
    double minimum_period_;
};

#endif  // TIMER_H_
