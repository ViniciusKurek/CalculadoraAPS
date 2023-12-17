#pragma once

#include <string>

class Form{

protected:
    std::string comment;

public:
    Form(std::string comment = "");

    std::string getComment();
    void setComment(const std::string& comment);

};