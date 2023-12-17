#pragma once

#include "../Model/Stage.h"
#include <vector>

class StageDAO{

private:
    std::vector<Stage> stages;    

public:
    StageDAO() = default;
    Stage& create(std::string name);
    std::vector<Stage>& retrieve();
    Stage& retrieve(std::string stageId);
    void update(Stage& stage);
    void remove(Stage& stage);
    
};