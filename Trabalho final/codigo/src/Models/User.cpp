#include "User.h"

User::User(std::string id, std::string name, std::string password){
    this->id = id;
    this->name = name;
    this->password = password;
}

std::string User::getId(){ return this->id;}
std::string User::getName(){ return this->name; }
std::string User::getPassword(){ return this->password;}
void User::setId(std::string id){ this->id = id;}
void User::setName(std::string name){ this->name = name; }
void User::setPassword(std::string password){ this->password = password; }