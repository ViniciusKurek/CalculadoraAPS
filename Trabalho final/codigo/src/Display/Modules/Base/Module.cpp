#include "Module.h"

Module::Module(std::string name) : name(name) {}
std::string Module::getName(){ return this->name; }
std::vector<Module*> Module::getNavigations(){ return this->navigations; }