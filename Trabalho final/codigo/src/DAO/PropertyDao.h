#pragma once

#include "../Model/Property.h"
#include "OwnerDAO.h"
#include <string>
#include <vector>

class PropertyDAO{

private:
    OwnerDAO& ownerDAO;
    std::vector<Property> properties;

public:
    PropertyDAO(OwnerDAO& ownerDAO);
    Property& create(
        const std::string& ownerId,
        const std::string& name,
        const std::string& highway,
        const std::string& state,
        const std::string& city,
        const std::string& neighborhood);
    std::vector<Property>& retrieve();
    Property& retrieve(const std::string& propertyId);
    std::vector<Property>& retrieveOwner(std::string ownerId);
    void update(Property& property);
    void remove(Property& property);
    OwnerDAO& getOwnerDAO();

};