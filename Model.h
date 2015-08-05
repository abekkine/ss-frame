// Copyright 2015 A.Bekkine

#ifndef MODEL_H_
#define MODEL_H_

#include "Task.h"

class Model : public Task {
 public:
    virtual void ModelStep() = 0;
    virtual ~Model() {}

 public:
    void Step();
};

#endif  // MODEL_H_
