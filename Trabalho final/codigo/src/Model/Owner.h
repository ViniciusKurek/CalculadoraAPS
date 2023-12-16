#pragma once

#include "User.h"
#include <string>

class Owner : public User{

    public:
    Owner(std::string id, std::string name, std::string email, std::string password);

};