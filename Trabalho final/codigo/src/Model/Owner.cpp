#include "Owner.h"

Owner::Owner(std::string id, std::string name, std::string email, std::string password) 
    : User(id, name, email, password) { }

std::vector<Property>& Owner::getProperties(){ return this->properties; }