// Copyright 2015 A.Bekkine

#include "TaskManager.h"

TaskManager::TaskManager() {
    Setup();
}

TaskManager::~TaskManager() {
    Cleanup();
}

void TaskManager::Setup() {
    frequencies_.clear();
    models_.clear();
    interfaces_.clear();

    // TODO(abekkine) : More initialization...
}

void TaskManager::Cleanup() {
    // Some cleanup
    CleanupModels();
    CleanupInterfaces();
}

void TaskManager::CleanupModels() {
    // Clean up models.
    while (!models_.empty()) {
        Model* modelToDelete = models_.back();
        models_.pop_back();
        delete modelToDelete;
    }
}

void TaskManager::CleanupInterfaces() {
    // Clean up interfaces.
    while (!interfaces_.empty()) {
        Interface* interfaceToDelete = interfaces_.back();
        interfaces_.pop_back();
        delete interfaceToDelete;
    }
}

void TaskManager::AddModel(Model* modelInstance, double frequencyInHz) {
    // Add a model instance.
    // We collect all frequencies to calculate a schedule plan.
    frequencies_.push_back(frequencyInHz);
    models_.push_back(modelInstance);
    // Model should know it's frequency, too.
    modelInstance->Frequency(frequencyInHz);
}

void TaskManager::AddInterface(Interface* interfaceInstance, double frequencyInHz) {
    // Add an interface instance.
    // We collect all frequencies to calculate a schedule plan.
    frequencies_.push_back(frequencyInHz);
    interfaces_.push_back(interfaceInstance);
    // Interface should know it's frequency.
    interfaceInstance->Frequency(frequencyInHz);
}

void TaskManager::Initialize() {
    // First, calculate scheduling plan for given
    // models and interfaces.
    CalculateSchedulePlan();

    // Setup timing resolution for models and interfaces.
    // TODO(abekkine) : Following method will be called with minimum scheduling
    //                : period from scheduling plan to setup task scheduling.
    Task::TimeResolution(0.0);

    // Prepare timer for scheduling.
    SetupTimer();

    // Prepare interfaces for scheduling.
    SetupInterfaces();

    // Prepare models for scheduling.
    SetupModels();
}

void TaskManager::CalculateSchedulePlan() {
    // TODO(abekkine) : Calculate schedule plan for
    //                : given model and interface frequencies
}

void TaskManager::SetupTimer() {
    // TODO(abekkine) : Setup scheduling timer.
}

void TaskManager::SetupInterfaces() {
    // TODO(abekkine) : Setup & initialize scheduling for interfaces.
}

void TaskManager::SetupModels() {
    // TODO(abekkine) : Setup & initialize scheduling for models.
}

void TaskManager::Execute() {
    // TODO(abekkine) : Start scheduling.
}
