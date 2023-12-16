#include "OwnerDAO.h"

Owner& OwnerDAO::create(std::string nome, std::string email, std::string senha){
    // OBTENDO O NOVO ID A SER INSERIDO
    std::string id = "1";
    if(this->owners.size() > 0)
        id = std::to_string(std::stoi(this->owners.back().getId()) + 1);

    Owner* owner = new Owner(id, nome, email, senha);
    this->owners.push_back(*owner);
    return *owner;
}

std::vector<Owner>& OwnerDAO::retrieve(){
    return this->owners;
}

Owner& OwnerDAO::retrieve(std::string ownerId){
    for(auto& o : this->owners){
        if(o.getId() == ownerId){
            return o;
        }
    }
    throw "Proprietário não encontrado";
}

void OwnerDAO::update(Owner& owner){
    for(auto& o : this->owners){
        if(o.getId() == owner.getId()){
            o = owner;
            return;
        }
    }
}

void OwnerDAO::remove(Owner& owner){
    for(auto it = this->owners.begin(); it != this->owners.end(); it++){
        if(it->getId() == owner.getId()){
            this->owners.erase(it);
            return;
        }
    }
}