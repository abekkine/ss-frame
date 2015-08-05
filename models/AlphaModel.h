// Copyright 2015 A.Bekkine

#ifndef ALPHA_MODEL_H_
#define ALPHA_MODEL_H_

#include "../Model.h"

class AlphaModel : public Model {
 public:
    AlphaModel();
    ~AlphaModel();
    void Initialize();
    void ModelStep();

 private:
    void Setup();
    void Cleanup();
};

#endif  // ALPHA_MODEL_H_
