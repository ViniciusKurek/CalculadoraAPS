#pragma once

#include "../Model/ProjectStage.h"
#include "ProjectDAO.h"
#include "StageDAO.h"
#include <vector>

class ProjectStageDAO{

private:
    std::vector<ProjectStage> projectStages;    
    ProjectDAO& projectDAO;
    StageDAO& stageDAO;

public:
    ProjectStageDAO(ProjectDAO& projectDAO, StageDAO& stageDAO);
    ProjectStage& create(std::string stageId, std::string projectId);
    std::vector<ProjectStage>& retrieve();
    ProjectStage& retrieve(std::string projectStageId);
    std::vector<ProjectStage>& retrieveStage(std::string stageId);
    std::vector<ProjectStage>& retrieveProject(std::string projectId);
    std::vector<ProjectStage>& retrieveProject(std::string projectId, ProjectStageStatus status);
    void update(ProjectStage& projectStage);
    void remove(ProjectStage& projectStage);

};