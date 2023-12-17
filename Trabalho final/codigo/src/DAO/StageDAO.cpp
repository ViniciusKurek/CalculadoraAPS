#include "StageDAO.h"

Stage& StageDAO::create(std::string name){
    // OBTENDO O NOVO ID A SER INSERIDO
    std::string id = "1";
    if (this->stages.size() > 0)
        id = std::to_string(std::stoi(this->stages.back().getId()) + 1);

    Stage* stage = new Stage(id, name);
    this->stages.push_back(*stage);
    return *stage;
}

std::vector<Stage>& StageDAO::retrieve(){
    return this->stages;
}

Stage& StageDAO::retrieve(std::string stageId){
    for (auto& s : this->stages){
        if (s.getId() == stageId){
            return s;
        }
    }
    throw "Etapa não encontrado";
}

void StageDAO::update(Stage& stage){
    for (auto& s : this->stages){
        if (s.getId() == stage.getId()){
            s.setName(stage.getName());
            return;
        }
    }
}

void StageDAO::remove(Stage& stage){
    for (auto it = this->stages.begin(); it != this->stages.end(); ++it){
        if (it->getId() == stage.getId()){
            this->stages.erase(it);
            return;
        }
    }
}