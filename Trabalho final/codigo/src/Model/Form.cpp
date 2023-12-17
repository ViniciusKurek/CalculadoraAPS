#include "Form.h"

Form::Form(std::string comment) : comment(comment){}
std::string Form::getComment(){ return this->comment; }
void Form::setComment(const std::string& comment){ this->comment = comment; }