#pragma once

#include "ProjectStage.h"
#include <string>
#include <vector>

namespace ProjectStatus{
    enum Status{
        PENDENTE, FINALIZADO
    };
}

class Project{

private:
    std::vector<ProjectStage> projectStages;
    
protected:
    std::string id;
    std::string name;
    std::string description;
    ProjectStatus::Status status;
    float result;

public:
    Project(std::string id, 
        std::string name, 
        std::string description, 
        ProjectStatus::Status status, 
        float result);
    
    std::string getId() const;
    void setId(const std::string& id);
    
    std::string getName() const;
    void setName(const std::string& name);

    std::string getDescription() const;
    void setDescription(const std::string& description);

    ProjectStatus::Status getStatus() const;
    void setStatus(ProjectStatus::Status status);

    float getResult() const;
    void setResult(float result);

    std::vector<ProjectStage>& getProjectStages();

};