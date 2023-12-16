#include "ProjectDAO.h"

ProjectDAO::ProjectDAO(PropertyDAO& propertyDao) : propertyDao(propertyDao){}

Project& ProjectDAO::create(std::string propertyId, std::string name, std::string description){
    // OBTENDO O NOVO ID A SER INSERIDO
    std::string id = "1";
    if (this->projects.size() > 0)
        id = std::to_string(std::stoi(this->projects.back().getId()) + 1);

    Project* project = new Project(id, name, description, PENDENTE, 0);
    this->projects.push_back(*project);
    this->propertyDao.retrieve(propertyId).getProjects().push_back(*project);
    return *project;
}

std::vector<Project>& ProjectDAO::retrieve(){
    return this->projects;
}

Project& ProjectDAO::retrieve(std::string projectId){
    for (auto& p : this->projects){
        if (p.getId() == projectId){
            return p;
        }
    }
    throw "Projeto não encontrado";
}

std::vector<Project>& ProjectDAO::retrieveProperty(std::string propertyId){
    Property& property = this->propertyDao.retrieve(propertyId);
    std::vector<Project>& projects = property.getProjects();
    return projects;
}

std::vector<Project>& ProjectDAO::retrieveProperty(std::string propertyId, ProjectStatus status){
    Property& property = this->propertyDao.retrieve(propertyId);
    std::vector<Project>& projects = property.getProjects();
    std::vector<Project>* projectsByStatus = new std::vector<Project>();

    for (auto& p : projects)
        if (p.getStatus() == status)
            projectsByStatus->push_back(p);
    
    return *projectsByStatus;
}

void ProjectDAO::update(Project& project){
    for(auto& p : this->projects){
        if (p.getId() == project.getId()){
            p = project;
            break;
        }
    }

    for(auto& p : this->propertyDao.retrieve()){
        for (auto& pj : p.getProjects()){
            if (pj.getId() == project.getId()){
                pj = project;
                return;
            }
        }
    }
}

void ProjectDAO::remove(Project& project){
    for(auto it = this->projects.begin(); it != this->projects.end(); ++it){
        if (it->getId() == project.getId()){
            this->projects.erase(it);
            break;
        }
    }

    for(auto& p : this->propertyDao.retrieve()){
        for (auto it = p.getProjects().begin(); it != p.getProjects().end(); ++it){
            if (it->getId() == project.getId()){
                p.getProjects().erase(it);
                return;
            }
        }
    }
}

PropertyDAO &ProjectDAO::getPropertyDAO(){ return this->propertyDao; }