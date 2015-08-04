// Copyright 2015 A.Bekkine

#ifndef TASKMANAGER_H_
#define TASKMANAGER_H_

#include <vector>

#include "Model.h"
#include "Interface.h"
#include "SchedulePlan.h"
#include "Timer.h"

class TaskManager {
 public:
    static TaskManager* Instance();
    ~TaskManager();
    void AddModel(Model* modelInstance, double freqInHz);
    void AddInterface(Interface* interfaceInstance, double freqInHz);
    void Initialize();
    void Execute();

 private:
    static TaskManager* instance_;
    TaskManager();

 private:
    void Setup();
    void Cleanup();
    void CleanupModels();
    void CleanupInterfaces();
    void CalculateSchedulePlan();
    void SetupTimer();
    void StartupTimer();
    void SetupModels();
    void SetupInterfaces();
    void ScheduleInterfaces();
    void ScheduleModels();
    void UpdateFrameCounter();
    static void Handler();

 private:
    std::vector< double > frequencies_;
    std::vector< Model* > models_;
    std::vector< Interface* > interfaces_;
    SchedulePlan* plan_;
    Timer* timer_;
    int frame_counter_;
};

#endif  // TASKMANAGER_H_
