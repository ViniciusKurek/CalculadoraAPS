#include "ProjectStageDAO.h"
#include "../Manager/DAOManager.h"
#include <iostream>

ProjectStageDAO::ProjectStageDAO(ProjectDAO& projectDAO, StageDAO& stageDAO)
    : projectDAO(projectDAO), stageDAO(stageDAO) {}

ProjectStage& ProjectStageDAO::create(std::string stageId, std::string projectId){
    // OBTENDO O NOVO ID A SER INSERIDO
    std::string id = "1";
    if (this->projectStages.size() > 0)
        id = std::to_string(std::stoi(this->projectStages.back().getId()) + 1);

    Project project = this->projectDAO.retrieve(projectId);
    Stage stage = this->stageDAO.retrieve(stageId);

    ProjectStage* projectStage = new ProjectStage(id);
    projectStage->setStage(stage);

    project.getProjectStages().push_back(*projectStage);
    DAOManager::getProjectDAO().update(project);
    
    this->projectStages.push_back(*projectStage);
    return *projectStage;
}

std::vector<ProjectStage>& ProjectStageDAO::retrieve(){
    return this->projectStages;
}

ProjectStage& ProjectStageDAO::retrieve(std::string projectStageId){
    for (auto& ps : this->projectStages){
        if (ps.getId() == projectStageId){
            return ps;
        }
    }
    throw "Etapa de projeto não encontrada";
}

std::vector<ProjectStage>& ProjectStageDAO::retrieveStage(std::string stageId){
    std::vector<ProjectStage>* projectStages = new std::vector<ProjectStage>();
    for(auto& ps : this->projectStages)
        if(ps.getStage().getId() == stageId)
            projectStages->push_back(ps);
    return *projectStages;
}

std::vector<ProjectStage>& ProjectStageDAO::retrieveProject(std::string projectId){
    Project project = this->projectDAO.retrieve(projectId);
    return project.getProjectStages();
}

std::vector<ProjectStage>& ProjectStageDAO::retrieveProject(std::string projectId, ProjectStageStatus status){
    Project project = this->projectDAO.retrieve(projectId);
    std::vector<ProjectStage>* projectStages = new std::vector<ProjectStage>();
    for(auto& ps : project.getProjectStages())
        if(ps.getStatus() == status)
            projectStages->push_back(ps);
    return *projectStages;
}

void ProjectStageDAO::update(ProjectStage& projectStage){
    for(auto& ps : this->projectStages){
        if (ps.getId() == projectStage.getId()){
            ps = projectStage;
            break;
        }
    }

    for(auto& p : this->projectDAO.retrieve()){
        for (auto& ps : p.getProjectStages()){
            if (ps.getId() == projectStage.getId()){
                ps = projectStage;
                return;
            }
        }
    }
}

void ProjectStageDAO::remove(ProjectStage& projectStage){
    for(auto it = this->projectStages.begin(); it != this->projectStages.end(); ++it){
        if (it->getId() == projectStage.getId()){
            this->projectStages.erase(it);
            break;
        }
    }

    for(auto& p : this->projectDAO.retrieve()){
        for(auto it = p.getProjectStages().begin(); it != p.getProjectStages().end(); ++it){
            if (it->getId() == projectStage.getId()){
                p.getProjectStages().erase(it);
                return;
            }
        }
    }
}