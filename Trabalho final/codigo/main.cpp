#include <iostream>
#ifdef _WIN32
    #include <windows.h>
#endif

#include "src/DAO/OwnerDAO.h"

int main(){
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
    #endif

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

    return 0;
}