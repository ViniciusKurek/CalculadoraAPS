#pragma once

#include "User.h"
#include "Property.h"
#include <string>
#include <vector>

class Owner : public User{

private:
    std::vector<Property> properties;

public:
    Owner(std::string id, std::string name, std::string email, std::string password);

    std::vector<Property>& getProperties();

};