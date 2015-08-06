// Copyright 2015 A.Bekkine

#ifndef TIMER_H_
#define TIMER_H_

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

class Timer {
 public:
    static Timer* Instance();
    ~Timer();
    void SetHandler(void (*handler)());
    void SetMinimumPeriod(double minimum_period);
    void Initialize();
    void Start();
    void CallManagerHandler();

 private:
    static Timer* instance_;
    Timer();
    void HandleOverrun(siginfo_t* info);
    void HandleContext(void* context);
    static void SignalHandler(int signal, siginfo_t* info, void* context);

 private:
    void (*manager_handler_)();
    double minimum_period_;
    timer_t timer_id_;
    int timer_signal_;
    struct sigevent sig_event_;
    struct itimerspec timer_spec_;
    sigset_t mask_;
    struct sigaction sig_action_;
    void* last_context_;
};

#endif  // TIMER_H_
