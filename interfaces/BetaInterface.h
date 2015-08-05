// Copyright 2015 A.Bekkine

#ifndef BETA_INTERFACE_H_
#define BETA_INTERFACE_H_

#include "../Interface.h"

class BetaInterface : public Interface {
 public:
    BetaInterface();
    ~BetaInterface();
    void Initialize();
    void Send();
    void Receive();
    int Size();
    void Update();
};

#endif  // BETA_INTERFACE_H_
