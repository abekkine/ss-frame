// Copyright 2015 A.Bekkine

#include "Model.h"

void Model::Step() {
    if (OnTime() == true) {
        ModelStep();
    }
}
