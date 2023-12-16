#pragma once

#include <string>

class User{

protected:
    std::string id;
    std::string name;
    std::string password;

public:
    User(std::string id, std::string name, std::string password);
    std::string getId() const;
    void setId(const std::string& id);
    std::string getName() const;
    void setName(const std::string& name);
    std::string getPassword() const;
    void setPassword(const std::string& password);

};
