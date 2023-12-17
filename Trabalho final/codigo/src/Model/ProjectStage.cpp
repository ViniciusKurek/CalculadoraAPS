#include "ProjectStage.h"

ProjectStage::ProjectStage(std::string id, float result, ProjectStageStatus status)
    : id(id), result(result), status(status) {}

std::string ProjectStage::getId(){ return this->id; }
void ProjectStage::setId(const std::string& id){ this->id = id; }

float ProjectStage::getResult(){ return this->result; }
void ProjectStage::setResult(float result){ this->result = result; }

ProjectStageStatus ProjectStage::getStatus(){ return this->status; }
void ProjectStage::setStatus(ProjectStageStatus status){ this->status = status; }

Stage& ProjectStage::getStage(){ return this->stage; }