// Copyright 2015 A.Bekkine

#include "TaskManager.h"

TaskManager::TaskManager() {
    // TODO(abekkine) : CTOR
}

TaskManager::~TaskManager() {
    // TODO(abekkine) : DTOR
}

void TaskManager::AddModel(Model* modelInstance, double frequencyInHz) {
    // TODO(abekkine) : Add a model instance.
    modelInstance = modelInstance;
    frequencyInHz = frequencyInHz;
}

void TaskManager::AddInterface(Interface* interfaceInstance, double frequencyInHz) {
    // TODO(abekkine) : Add an interface instance.
    interfaceInstance = interfaceInstance;
    frequencyInHz = frequencyInHz;
}

void TaskManager::Initialize() {
    // TODO(abekkine) : Initialize task manager.
}

void TaskManager::Execute() {
    // TODO(abekkine) : Start scheduling.
}
