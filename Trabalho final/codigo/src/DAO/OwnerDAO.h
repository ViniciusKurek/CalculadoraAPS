#pragma once

#include "../Model/Owner.h"
#include <string>

class OwnerDAO{

    public:
    Owner* create(std::string nome, std::string email, std::string senha);

};