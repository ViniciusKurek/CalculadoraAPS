#include "FormularioManager.h"

void FormularioManager::approveForm(std::string projectStageId, std::string comment){
    ProjectStage projectStage = DAOManager::getProjectStageDAO().retrieve(projectStageId);
    if(projectStage.getStatus() == ProjectStageStatus::APROVADO || projectStage.getStatus() == ProjectStageStatus::RECUSADO){
        throw "O formulário informado deve estar com o status PENDENTE ou ENVIADO para ser aprovado";
        return;
    }
    
    projectStage.setStatus(ProjectStageStatus::APROVADO);
}

void FormularioManager::repproveForm(std::string projectStageId, std::string comment){
    ProjectStage projectStage = DAOManager::getProjectStageDAO().retrieve(projectStageId);
    if(projectStage.getStatus() == ProjectStageStatus::APROVADO || projectStage.getStatus() == ProjectStageStatus::RECUSADO){
        throw "O formulário informado deve estar com o status PENDENTE ou ENVIADO para ser recusado";
        return;
    }
    
    projectStage.setStatus(ProjectStageStatus::RECUSADO);
}

void FormularioManager::feedbackForm(std::string projectStageId, std::string comment, bool aprove){
    if(aprove) approveForm(projectStageId, comment);
    else repproveForm(projectStageId, comment);
}