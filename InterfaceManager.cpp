// Copyright 2015 A.Bekkine

#include "InterfaceManager.h"

#include "Interface.h"

void InterfaceManager::AddInterfaces(TaskManager* taskManager) {
    taskManager->AddInterface( new Interface(), 20.0 );
}
