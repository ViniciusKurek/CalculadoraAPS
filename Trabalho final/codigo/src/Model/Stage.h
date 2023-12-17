#pragma once

#include <string>

class Stage{

private:
    std::string id;
    std::string name;

public:
    Stage() = default;
    Stage(std::string id, std::string name);

    std::string getId();
    void setId(std::string id);

    std::string getName();
    void setName(std::string name);

};