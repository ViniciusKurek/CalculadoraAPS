#include "PropertyDao.h"

PropertyDAO::PropertyDAO(OwnerDAO& ownerDAO) : ownerDAO(ownerDAO) { }

Property& PropertyDAO::create(
    const std::string& ownerId,
    const std::string& name,
    const std::string& highway,
    const std::string& state,
    const std::string& city,
    const std::string& neighborhood)
{
    // OBTENDO O NOVO ID A SER INSERIDO
    std::string id = "1";
    if (this->properties.size() > 0)
        id = std::to_string(std::stoi(this->properties.back().getId()) + 1);

    Property* property = new Property(id, name, highway, state, city, neighborhood);
    this->properties.push_back(*property);
    this->ownerDAO.retrieve(ownerId).getProperties().push_back(*property);
    return *property;
}

std::vector<Property>& PropertyDAO::retrieve(){
    return this->properties;
}

Property& PropertyDAO::retrieve(const std::string& propertyId){
    for (auto& p : this->properties){
        if (p.getId() == propertyId){
            return p;
        }
    }
    throw "Propriedade não encontrado";
}

std::vector<Property>& PropertyDAO::retrieveOwner(std::string ownerId){
    Owner& owner = this->ownerDAO.retrieve(ownerId);
    std::vector<Property>& properties = owner.getProperties();
    return properties;
}

void PropertyDAO::update(Property& property){
    for(auto& p : this->properties){
        if (p.getId() == property.getId()){
            p = property;
            break;
        }
    }

    for(auto& o : this->ownerDAO.retrieve()){
        for (auto& p : o.getProperties()){
            if (p.getId() == property.getId()){
                p = property;
                return;
            }
        }
    }
}

void PropertyDAO::remove(Property& property){
    for(auto it = this->properties.begin(); it != this->properties.end(); ++it){
        if (it->getId() == property.getId()){
            this->properties.erase(it);
            break;
        }
    }

    for(auto& o : this->ownerDAO.retrieve()){
        for (auto it = o.getProperties().begin(); it != o.getProperties().end(); ++it){
            if (it->getId() == property.getId()){
                o.getProperties().erase(it);
                return;
            }
        }
    }
}