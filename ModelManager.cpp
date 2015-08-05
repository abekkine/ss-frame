// Copyright 2015 A.Bekkine

#include "ModelManager.h"

#include "models/AlphaModel.h"

void ModelManager::AddModels(TaskManager* taskManager) {
    taskManager->AddModel( new AlphaModel(), 25.0 );
}

