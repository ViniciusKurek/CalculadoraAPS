#pragma once

#include "User.h"
#include <string>

class Owner : User{

    public:
    Owner(std::string id, std::string name, std::string password);

};