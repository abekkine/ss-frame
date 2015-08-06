// Copyright 2015 A.Bekkine

#include "Timer.h"

Timer* Timer::instance_ = 0;

Timer* Timer::Instance() {
    if (instance_ == 0) {
        instance_ = new Timer();
    }

    return instance_;
}

Timer::Timer() {
    minimum_period_ = 0.0;
    manager_handler_ = 0;
    timer_signal_ = SIGRTMIN;
    last_context_ = 0;
}

Timer::~Timer() {
    timer_delete(timer_id_);
}

void Timer::SetHandler(void (*handler)()) {
    // Set handler callback from TaskManager.
    manager_handler_ = handler;
}

void Timer::CallManagerHandler() {
    manager_handler_();
}

void Timer::SetMinimumPeriod(double minimum_period) {
    // Set minimum period value for setting up timer.
    minimum_period_ = minimum_period;
}

void Timer::Initialize() {
    // Establish handler for timer signal.
    sig_action_.sa_flags = SA_SIGINFO;
    sig_action_.sa_sigaction = Timer::SignalHandler;
    sigemptyset(&sig_action_.sa_mask);
    if (sigaction(timer_signal_, &sig_action_, NULL) == -1) {
        perror("sigaction");
        printf("%s:%d\n", __FILE__, __LINE__);
        exit(1);
    }

    // Block timer signal until being ready.
    sigemptyset(&mask_);
    sigaddset(&mask_, timer_signal_);
    if (sigprocmask(SIG_SETMASK, &mask_, NULL) == -1) {
        perror("sigprocmask");
        printf("%s:%d\n", __FILE__, __LINE__);
        exit(1);
    }

    // Create the timer.
    sig_event_.sigev_notify = SIGEV_SIGNAL;
    sig_event_.sigev_signo = timer_signal_;
    sig_event_.sigev_value.sival_ptr = &timer_id_;
    if (timer_create(CLOCK_REALTIME, &sig_event_, &timer_id_) == -1) {
        perror("timer_create");
        printf("%s:%d\n", __FILE__, __LINE__);
        exit(1);
    }

    // Setup frequency.
    timer_spec_.it_value.tv_sec = static_cast<int>(minimum_period_);
    timer_spec_.it_value.tv_nsec = static_cast<int>(minimum_period_ * 1000000000.0);
    timer_spec_.it_interval.tv_sec = timer_spec_.it_value.tv_sec;
    timer_spec_.it_interval.tv_nsec = timer_spec_.it_value.tv_nsec;
    if (timer_settime(timer_id_, 0, &timer_spec_, NULL) == -1) {
        perror("timer_settime");
        printf("%s:%d\n", __FILE__, __LINE__);
        exit(1);
    }

    // Timer is ready to start.
}

void Timer::Start() {
    // Start timer.
    puts("Timer::Start()");
    if (sigprocmask(SIG_UNBLOCK, &mask_, NULL) == -1) {
        perror("sigprocmask");
        printf("%s:%d\n", __FILE__, __LINE__);
        exit(1);
    }
}

void Timer::HandleOverrun(siginfo_t *info) {
    // Process and log overruns.
    timer_t *p_timer_id;
    int overrun_count;

    p_timer_id = static_cast<timer_t *>(info->si_value.sival_ptr);
    overrun_count = timer_getoverrun(*p_timer_id);
    if (overrun_count == -1) {
        perror("timer_getoverrun");
        printf("%s:%d\n", __FILE__, __LINE__);
        exit(1);
    } else {
        if (overrun_count > 0) {
            printf("overrun_count(%d)\n", overrun_count);
        }
    }
}

void Timer::HandleContext(void* context) {
    if (last_context_ != 0) {
        if (context != last_context_) {
            puts("Signal context updated!");
            last_context_ = context;
        }
    } else {
        last_context_ = context;
    }
}

void Timer::SignalHandler(int signal, siginfo_t *info, void* context) {
    if (signal != SIGRTMIN) {
        // Process only specified signal.
        return;
    }

    Timer::Instance()->CallManagerHandler();

    Timer::Instance()->HandleOverrun(info);

    Timer::Instance()->HandleContext(context);
}
