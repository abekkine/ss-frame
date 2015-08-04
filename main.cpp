// Copyright 2015 A.Bekkine

#include "ModelManager.h"
#include "InterfaceManager.h"
#include "TaskManager.h"

int main() {
    // Initialize our task manager.
    TaskManager* taskManager = TaskManager::Instance();

    // Add -multiple- models to task manager.
    ModelManager::AddModels(taskManager);

    // Add -multiple- interfaces to task manager.
    InterfaceManager::AddInterfaces(taskManager);

    // Initialize everything.
    taskManager->Initialize();

    // Start running.
    taskManager->Execute();

    // When (if) done, clean up and exit.
    delete taskManager;

    return 0;
}
