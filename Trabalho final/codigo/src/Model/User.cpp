#include "User.h"

User::User(std::string id, std::string name, std::string password){
    this->id = id;
    this->name = name;
    this->password = password;
}

std::string User::getId() const{ return this->id; }
void User::setId(const std::string& id){ this->id = id; }
std::string User::getName() const{ return this->name; }
void User::setName(const std::string& name){ this->name = name; }
std::string User::getPassword() const{ return this->password; }
void User::setPassword(const std::string& password){ this->password = password; }