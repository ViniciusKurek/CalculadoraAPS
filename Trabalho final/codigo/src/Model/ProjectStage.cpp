#include "ProjectStage.h"

ProjectStage::ProjectStage(std::string id, float result, ProjectStageStatus status)
    : id(id), result(result), status(status) 
{
    this->form = Form();
}

std::string ProjectStage::getId(){ return this->id; }
void ProjectStage::setId(const std::string& id){ this->id = id; }

float ProjectStage::getResult(){ return this->result; }
void ProjectStage::setResult(float result){ this->result = result; }

ProjectStageStatus ProjectStage::getStatus(){ return this->status; }
void ProjectStage::setStatus(ProjectStageStatus status){ this->status = status; }

std::string ProjectStage::getComment(){ return this->form.getComment(); }
void ProjectStage::setComment(const std::string& comment){ this->form.setComment(comment); }

Stage& ProjectStage::getStage(){ return this->stage; }
void ProjectStage::setStage(const Stage& stage){ this->stage = stage; }

std::string ProjectStage::ProjectStageStatusToString(ProjectStageStatus status){
    switch(status){
        case ProjectStageStatus::PENDENTE:
            return "PENDENTE";
        case ProjectStageStatus::ENVIADO:
            return "ENVIADO";
        case ProjectStageStatus::APROVADO:
            return "APROVADO";
        case ProjectStageStatus::RECUSADO:
            return "RECUSADO";
    }
    return "";
}
