#pragma once

#include <string>
#include <vector>
#include "Project.h"

class Property{

private:
    std::vector<Project> projects;
    
protected:
    std::string id;
    std::string name;
    std::string highway;
    std::string state;
    std::string city;
    std::string neighborhood;

public:
    Property(
        const std::string& id, 
        const std::string& name, 
        const std::string& highway, 
        const std::string& state, 
        const std::string& city, 
        const std::string& neighborhood);
    
    std::string getId() const;
    void setId(const std::string& id);
    
    std::string getName() const;
    void setName(const std::string& name);
    
    std::string getHighway() const;
    void setHighway(const std::string& highway);
    
    std::string getState() const;
    void setState(const std::string& state);
    
    std::string getCity() const;
    void setCity(const std::string& city);
    
    std::string getNeighborhood() const;
    void setNeighborhood(const std::string& neighborhood);

    std::vector<Project>& getProjects();
};