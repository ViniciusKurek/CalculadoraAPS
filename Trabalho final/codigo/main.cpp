#include <iostream>
#ifdef _WIN32
    #include <windows.h>
#endif

#include "src/DAO/OwnerDAO.h"
#include "src/DAO/PropertyDAO.h"
#include "src/DAO/ProjectDAO.h"

int main(){
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
    #endif

    try{
    
    std::cout << "TESTANDO CRUD OWNER" << std::endl << std::endl;

    OwnerDAO ownerDAO;
    ownerDAO.create("João", "joao@gmail.com", "123");
    Owner& matheus = ownerDAO.create("Matheus", "matheus@gmail.com", "123");
    ownerDAO.create("Fernando", "fernando@gmail.com", "123");
    ownerDAO.remove(matheus);

    std::vector<Owner>& owners = ownerDAO.retrieve();
    for(auto& o : owners){
        std::cout << o.getId() << " - " << o.getName() << " - " << o.getEmail() << " - " << o.getPassword() << std::endl;
    }

    auto owner = ownerDAO.retrieve("3");
    owner.setName("Fernando 2");
    ownerDAO.update(owner);

    std::cout << std::endl;

    std::vector<Owner>& owners2 = ownerDAO.retrieve();
    for(auto& o : owners2){
        std::cout << o.getId() << " - " << o.getName() << " - " << o.getEmail() << " - " << o.getPassword() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "TESTANDO CRUD PROPERTY" << std::endl << std::endl;

    PropertyDAO propertyDAO(ownerDAO);
    propertyDAO.create("1", "Casa 1", "BR-101", "SC", "Florianópolis", "Centro");
    propertyDAO.create("1", "Casa 2", "BR-101", "SC", "Florianópolis", "Centro");
    propertyDAO.create("3", "Chácara é os guri", "BR-312", "PR", "Campo Mourão", "Centro");

    std::cout << "TODAS AS PROPRIEDADES" << std::endl;

    std::vector<Property>& properties = propertyDAO.retrieve();
    for(auto& p : properties)
        std::cout << p.getId() << " - " << p.getName() << " - " << p.getHighway() << " - " << p.getState() << " - " << p.getCity() << " - " << p.getNeighborhood() << std::endl;

    std::cout << std::endl;

    std::cout << "TODAS AS PROPRIEDADES DO DONO 1" << std::endl;

    auto property = propertyDAO.retrieveOwner("1");
    for(auto& p : property)
        std::cout << p.getId() << " - " << p.getName() << " - " << p.getHighway() << " - " << p.getState() << " - " << p.getCity() << " - " << p.getNeighborhood() << std::endl;


    std::cout << "TESTANDO UPDATE" << std::endl << std::endl;

    auto property2 = propertyDAO.retrieve("1");
    property2.setName("Casa 1 Atualizada");
    propertyDAO.update(property2);

    std::cout << "TODAS AS PROPRIEDADES" << std::endl;

    for(auto& p : properties)
        std::cout << p.getId() << " - " << p.getName() << " - " << p.getHighway() << " - " << p.getState() << " - " << p.getCity() << " - " << p.getNeighborhood() << std::endl;
    std::cout << std::endl;

    std::cout << "TESTANDO DELETE" << std::endl << std::endl;

    propertyDAO.remove(property2);
    for(auto& p : properties)
        std::cout << p.getId() << " - " << p.getName() << " - " << p.getHighway() << " - " << p.getState() << " - " << p.getCity() << " - " << p.getNeighborhood() << std::endl;

    std::cout << std::endl;

    std::cout << "TESTANDO CRUD PROJECT" << std::endl << std::endl;

    ProjectDAO projectDAO(propertyDAO);
    projectDAO.create("2", "Projeto 1", "Descrição 1");
    projectDAO.create("2", "Projeto 2", "Descrição 2");
    projectDAO.create("3", "Projeto 1", "Descrição 1");

    std::cout << "TODOS OS PROJETOS" << std::endl;

    std::vector<Project>& projects = projectDAO.retrieve();
    for(auto& p : projects)
        std::cout << p.getId() << " - " << p.getName() << " - " << p.getDescription() << " - " << p.getStatus() << " - " << p.getResult() << std::endl;

    std::cout << std::endl;

    std::cout << "TODOS OS PROJETOS DA PROPRIEDADE 2" << std::endl;

    auto project = projectDAO.retrieveProperty("2");
    for(auto& p : project)
        std::cout << p.getId() << " - " << p.getName() << " - " << p.getDescription() << " - " << p.getStatus() << " - " << p.getResult() << std::endl;

    std::cout << std::endl;

    std::cout << "TESTANDO UPDATE" << std::endl << std::endl;

    auto project2 = projectDAO.retrieve("1");
    project2.setName("Projeto 1 Atualizado");
    projectDAO.update(project2);

    for(auto& p : projects)
        std::cout << p.getId() << " - " << p.getName() << " - " << p.getDescription() << " - " << p.getStatus() << " - " << p.getResult() << std::endl;

    std::cout << std::endl;

    std::cout << "TESTANDO DELETE" << std::endl << std::endl;

    projectDAO.remove(project2);

    for(auto& p : projects)
        std::cout << p.getId() << " - " << p.getName() << " - " << p.getDescription() << " - " << p.getStatus() << " - " << p.getResult() << std::endl;

    }
    catch(const char* e){
        std::cout << e << std::endl;
    }

    return 0;
}