#pragma once

#include <string>
#include "DAOManager.h"

class FormularioManager{

private:
    void approveForm(std::string projectStageId, std::string comment);
    void repproveForm(std::string projectStageId, std::string comment);

public:
    FormularioManager();
    void feedbackForm(std::string ownerId, std::string comment, bool aprove);

};