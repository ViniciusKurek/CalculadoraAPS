#pragma once

#include <string>

class User{

    protected:
    std::string id;
    std::string name;
    std::string password;

    public:
    User(std::string id, std::string name, std::string password);
    User() = default;
    std::string getId();
    std::string getName();
    std::string getPassword();
    void setId(std::string id);
    void setName(std::string name);
    void setPassword(std::string password);
    
};