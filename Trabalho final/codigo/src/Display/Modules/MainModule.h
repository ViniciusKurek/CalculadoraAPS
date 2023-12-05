#pragma once

#include "Base/Module.h"

class MainModule : public Module{
    
    public:
    MainModule(std::string) : Module("MainModule") {};
    std::vector<std::string> getContent() override;
};