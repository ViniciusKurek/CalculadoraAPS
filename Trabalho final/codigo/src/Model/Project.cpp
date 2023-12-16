#include "Project.h"

Project::Project(std::string id, 
    std::string name, 
    std::string description, 
    ProjectStatus status, 
    float result)
{
    this->id = id;
    this->name = name;
    this->description = description;
    this->status = status;
    this->result = result;
}

std::string Project::getId() const{ return this->id; }
void Project::setId(const std::string& id){ this->id = id; }

std::string Project::getName() const{ return this->name; }
void Project::setName(const std::string& name){ this->name = name; }

std::string Project::getDescription() const{ return this->description; }
void Project::setDescription(const std::string& description){ this->description = description; }

ProjectStatus Project::getStatus() const{ return this->status; }
void Project::setStatus(ProjectStatus status){ this->status = status; }

float Project::getResult() const{ return this->result; }
void Project::setResult(float result){ this->result = result; }