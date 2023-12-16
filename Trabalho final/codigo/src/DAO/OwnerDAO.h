#pragma once

#include "../Model/Owner.h"
#include <string>
#include <vector>

class OwnerDAO{

private:
    std::vector<Owner*> owners;

public:
    Owner* create(std::string nome, std::string email, std::string senha);
    std::vector<Owner*> retrieve();
    Owner* retrieve(std::string ownerId);
    void update(Owner* owner);
    void remove(Owner* owner);

};