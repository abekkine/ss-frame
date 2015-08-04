// Copyright 2015 A.Bekkine

#ifndef TASKMANAGER_H_
#define TASKMANAGER_H_

#include <vector>

#include "Model.h"
#include "Interface.h"
#include "SchedulePlan.h"

class TaskManager {
 public:
    TaskManager();
    ~TaskManager();
    void AddModel(Model* modelInstance, double freqInHz);
    void AddInterface(Interface* interfaceInstance, double freqInHz);
    void Initialize();
    void Execute();

 private:
    void Setup();
    void Cleanup();
    void CleanupModels();
    void CleanupInterfaces();
    void CalculateSchedulePlan();
    void SetupTimer();
    void SetupModels();
    void SetupInterfaces();

 private:
    std::vector< double > frequencies_;
    std::vector< Model* > models_;
    std::vector< Interface* > interfaces_;
    SchedulePlan* plan_;
};

#endif  // TASKMANAGER_H_
