// Copyright 2015 A.Bekkine

#include "Model.h"
#include "Interface.h"
#include "TaskManager.h"

int main() {
    // Initialize our task manager.
    TaskManager* taskManager = new TaskManager();

    // TODO(abekkine) : Add models with frequencies to task manager.
    // Start with a simple model with arbitrary frequency value.
    taskManager->AddModel( new Model(), 25.0 );

    // TODO(abekkine) : Add interfaces with frequencies to task manager.
    // Start with a simple interface with arbitrary frequency value.
    taskManager->AddInterface( new Interface(), 20.0 );

    // Initialize everything.
    taskManager->Initialize();

    // Start running.
    taskManager->Execute();

    // When (if) done, clean up and exit.
    delete taskManager;

    return 0;
}
