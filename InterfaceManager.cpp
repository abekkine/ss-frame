// Copyright 2015 A.Bekkine

#include "InterfaceManager.h"

#include "interfaces/BetaInterface.h"

void InterfaceManager::AddInterfaces(TaskManager* taskManager) {
    taskManager->AddInterface( new BetaInterface(), 20.0 );
}
