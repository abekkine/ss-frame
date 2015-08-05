// Copyright 2015 A.Bekkine

#ifndef INTERFACE_H_
#define INTERFACE_H_

#include "Task.h"

class Interface : public Task {
 public:
    virtual void Update() = 0;
    virtual void Send() = 0;
    virtual void Receive() = 0;

 public:
    Interface();
    virtual ~Interface() {}

 public:
    void Step();

 private:
    char direction_;
};

#endif  // INTERFACE_H_
