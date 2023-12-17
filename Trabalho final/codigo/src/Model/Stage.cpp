#include "Stage.h"

Stage::Stage(std::string id, std::string name){
    this->id = id;
    this->name = name;
}

std::string Stage::getId(){ return this->id; }
void Stage::setId(std::string id){ this->id = id; }

std::string Stage::getName(){ return this->name; }
void Stage::setName(std::string name){ this->name = name; }