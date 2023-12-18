#include "FormularioManager.h"
#include <iostream>

void FormularioManager::approveForm(std::string projectStageId, std::string comment){
    ProjectStage projectStage = DAOManager::getProjectStageDAO().retrieve(projectStageId);
    if(projectStage.getStatus() != ProjectStageStatus::ENVIADO){
        throw "O formulário informado deve estar com o status ENVIADO para ser aprovado";
        return;
    }
    
    projectStage.setStatus(ProjectStageStatus::APROVADO);
    projectStage.setComment(comment);
    DAOManager::getProjectStageDAO().update(projectStage);
}

void FormularioManager::repproveForm(std::string projectStageId, std::string comment){
    ProjectStage projectStage = DAOManager::getProjectStageDAO().retrieve(projectStageId);
    if(projectStage.getStatus() != ProjectStageStatus::ENVIADO){
        throw "O formulário informado deve estar com o status ENVIADO para ser recusado";
        return;
    }
    
    projectStage.setStatus(ProjectStageStatus::RECUSADO);
    projectStage.setComment(comment);
    DAOManager::getProjectStageDAO().update(projectStage);
}

void FormularioManager::feedbackForm(std::string projectStageId, std::string comment, bool aprove){
    if(aprove) approveForm(projectStageId, comment);
    else repproveForm(projectStageId, comment);
}

void FormularioManager::getFeedbackForm(std::string projectStageId){
    ProjectStage projectStage = DAOManager::getProjectStageDAO().retrieve(projectStageId);
    if(projectStage.getStatus() == ProjectStageStatus::PENDENTE || projectStage.getStatus() == ProjectStageStatus::ENVIADO){
        throw "O formulário informado deve estar com o status APROVADO ou RECUSADO para ser visualizado";
        return;
    }
    

    std::cout << "Status: " << ProjectStage::ProjectStageStatusToString(projectStage.getStatus()) << std::endl;
    std::cout << "Etapa: " << projectStage.getStage().getName() << std::endl;
    std::cout << "Comentário: " << projectStage.getComment() << std::endl;
}