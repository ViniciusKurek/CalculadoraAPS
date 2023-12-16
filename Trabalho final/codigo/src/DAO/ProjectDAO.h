#pragma once

#include "PropertyDao.h"
#include <string>

class ProjectDAO{

private:
    PropertyDAO& propertyDao;
    std::vector<Project> projects;

public:
    ProjectDAO(PropertyDAO& propertyDao);
    Project& create(std::string propertyId, std::string name, std::string description);
    std::vector<Project>& retrieve();
    Project& retrieve(std::string projectId);
    std::vector<Project>& retrieveProperty(std::string propertyId);
    std::vector<Project>& retrieveProperty(std::string propertyId, ProjectStatus status);
    void update(Project& project);
    void remove(Project& project);
    PropertyDAO& getPropertyDAO();

};