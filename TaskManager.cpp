// Copyright 2015 A.Bekkine

#include "TaskManager.h"

TaskManager::TaskManager() {
    // TODO(abekkine) : CTOR
}

TaskManager::~TaskManager() {
    // TODO(abekkine) : DTOR
}

void TaskManager::AddModel(Model* modelInstance, double frequencyInHz) {
    // Add a model instance.
    // We collect all frequencies to calculate a schedule plan.
    frequencies_.push_back(frequencyInHz);
    models_.push_back(modelInstance);
    // TODO(abekkine) : Model should know it's frequency, too.
}

void TaskManager::AddInterface(Interface* interfaceInstance, double frequencyInHz) {
    // Add an interface instance.
    // We collect all frequencies to calculate a schedule plan.
    frequencies_.push_back(frequencyInHz);
    interfaces_.push_back(interfaceInstance);
    // TODO(abekkine) : Interface should know it's frequency.
}

void TaskManager::Initialize() {
    // TODO(abekkine) : Initialize task manager.
}

void TaskManager::Execute() {
    // TODO(abekkine) : Start scheduling.
}
