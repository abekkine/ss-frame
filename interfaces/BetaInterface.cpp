// Copyright 2015 A.Bekkine

#include <stdio.h>

#include "BetaInterface.h"

BetaInterface::BetaInterface() {
    // TODO(abekkine) : CTOR
    puts("BetaInterface::BetaInterface()");
}

BetaInterface::~BetaInterface() {
    // TODO(abekkine) : DTOR
    puts("BetaInterface::~BetaInterface()");
}

void BetaInterface::Initialize() {
    // TODO(abekkine) : Initialization
    puts("BetaInterface::Initialize()");
    SetupScheduling();
}

void BetaInterface::Send() {
    // TODO(abekkine) : Send data
    puts("BetaInterface::Send()");
}

void BetaInterface::Receive() {
    // TODO(abekkine) : Receive data
    puts("BetaInterface::Receive()");
}

void BetaInterface::Update() {
    // TODO(abekkine) : Update?
    puts("BetaInterface::Update()");
}

