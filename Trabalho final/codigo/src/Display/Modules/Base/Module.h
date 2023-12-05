#pragma once

#include <string>
#include <vector>

class Module{

    std::string name;
    std::vector<Module*> navigations;

    public:
    Module(std::string name);
    std::string getName();
    std::vector<Module*> getNavigations();
    virtual std::vector<std::string> getContent() = 0;

};