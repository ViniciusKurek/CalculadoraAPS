#pragma once

#include "User.h"
#include <string>

class Admin : User{

    public:
    Admin(std::string id, std::string name, std::string password);

};