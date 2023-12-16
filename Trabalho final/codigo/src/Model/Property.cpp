#include "Property.h"

Property::Property(
    const std::string &id, 
    const std::string &name, 
    const std::string &highway, 
    const std::string &state, 
    const std::string &city, 
    const std::string &neighborhood)
{
    this->id = id;
    this->name = name;
    this->highway = highway;
    this->state = state;
    this->city = city;
    this->neighborhood = neighborhood;
}

std::string Property::getId() const{ return this->id; }
void Property::setId(const std::string &id){ this->id = id; }

std::string Property::getName() const{ return this->name; }
void Property::setName(const std::string &name){ this->name = name; }

std::string Property::getHighway() const{ return this->highway; }
void Property::setHighway(const std::string &highway){ this->highway = highway; }

std::string Property::getState() const{ return this->state; }
void Property::setState(const std::string &state){ this->state = state; }

std::string Property::getCity() const{ return this->city; }
void Property::setCity(const std::string &city){ this->city = city; }

std::string Property::getNeighborhood() const{ return this->neighborhood; }
void Property::setNeighborhood(const std::string &neighborhood){ this->neighborhood = neighborhood; }