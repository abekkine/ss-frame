// Copyright 2015 A.Bekkine

#include <stdio.h>

#include "Interface.h"

Interface::Interface() {
    direction_ = 0;
}

void Interface::Step() {
    if (OnTime() == false) {
        return;
    }

    Update();

    switch (direction_) {
     case 'T':
        // Send (T)o
        Send();
        break;
     case 'F':
        // Receive (F)rom
        Receive();
        break;
     default:
        // Undefined direction.
        break;
    }
}

