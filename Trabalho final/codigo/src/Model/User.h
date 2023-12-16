#pragma once

#include <string>

class User{

protected:
    std::string id;
    std::string name;
    std::string email;
    std::string password;

public:
    User(std::string id, std::string name, std::string email, std::string password);
    std::string getId() const;
    void setId(const std::string& id);
    std::string getEmail() const;
    void setEmail(const std::string& email);
    std::string getName() const;
    void setName(const std::string& name);
    std::string getPassword() const;
    void setPassword(const std::string& password);

};
