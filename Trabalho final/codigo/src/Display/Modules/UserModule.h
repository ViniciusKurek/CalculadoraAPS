#pragma once

#include "Base/Module.h"

class UserModule : public Module{
    
    public:
    UserModule(std::string name) : Module(name){};
    std::vector<std::string> getContent();
};