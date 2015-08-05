// Copyright 2015 A.Bekkine

#include "ModelManager.h"

#include "Model.h"

void ModelManager::AddModels(TaskManager* taskManager) {
    taskManager->AddModel( new Model(), 25.0 );
}
