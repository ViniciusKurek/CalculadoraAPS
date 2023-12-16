#pragma once

#include <string>

enum ProjectStatus{
    PENDENTE, FINALIZADO
};

class Project{
    
protected:
    std::string id;
    std::string name;
    std::string description;
    ProjectStatus status;
    float result;

public:
    Project(std::string id, 
        std::string name, 
        std::string description, 
        ProjectStatus status, 
        float result);
    
    std::string getId() const;
    void setId(const std::string& id);
    
    std::string getName() const;
    void setName(const std::string& name);

    std::string getDescription() const;
    void setDescription(const std::string& description);

    ProjectStatus getStatus() const;
    void setStatus(ProjectStatus status);

    float getResult() const;
    void setResult(float result);

};