// Copyright 2015 A.Bekkine

#include "TaskManager.h"

TaskManager::TaskManager() {
    // TODO(abekkine) : CTOR
}

TaskManager::~TaskManager() {
    // TODO(abekkine) : DTOR
}

void TaskManager::AddModel(Model* modelInstance, double freqInHz) {
    // TODO(abekkine) : Add a model instance.
    modelInstance = modelInstance;
    freqInHz = freqInHz;
}

void TaskManager::AddInterface(Interface* interfaceInstance, double freqInHz) {
    // TODO(abekkine) : Add an interface instance.
    interfaceInstance = interfaceInstance;
    freqInHz = freqInHz;
}

void TaskManager::Initialize() {
    // TODO(abekkine) : Initialize task manager.
}

void TaskManager::Execute() {
    // TODO(abekkine) : Start scheduling.
}
