#include <iostream>
#include <limits>
#ifdef _WIN32
    #include <windows.h>
#endif

#include "src/Manager/DAOManager.h"
#include "src/Manager/FormularioManager.h"

void sendFeedbackForm(){
    std::string ownerId;
    std::string propertyId;
    std::string projectId;
    std::string projectStageId;
    std::string comment;
    std::string aprove;
    
    try{
        std::cout << "USUÁRIOS DISPONÍVEIS: " << std::endl;
        for(auto& owner : DAOManager::getOwnerDAO().retrieve())
            std::cout << "\t" << owner.getId() << " - " << owner.getName() << std::endl;
        std::cout << std::endl;

        std::cout << "Digite o id do usuário para buscar por suas propriedades: " << std::endl;
        std::cin >> ownerId;
        std::cout << std::endl;

        std::cout << "PROPRIEDADES:" << std::endl;
        for(auto& property : DAOManager::getPropertyDAO().retrieveOwner(ownerId))
            std::cout << "\t" << property.getId() << " - " << property.getName() << " - " << property.getHighway() << " - " << property.getCity() << " - " << property.getState() << " - " << property.getNeighborhood() << std::endl;
        std::cout << std::endl;

        std::cout << "Escolha uma propriedade para procurar por projetos:" << std::endl;
        std::cin >> propertyId;
        std::cout << std::endl;

        std::cout << "PROJETOS:" << std::endl;
        for(auto& project : DAOManager::getProjectDAO().retrieveProperty(propertyId))
            std::cout << "\t" << project.getId() << " - " << project.getName() << " - " << project.getDescription() << std::endl;
        std::cout << std::endl;

        std::cout << "Escolha um projeto para ver todas as suas etapas:" << std::endl;
        std::cin >> projectId;
        std::cout << std::endl;

        std::cout << "ETAPAS DO PROJETO:" << std::endl;
        for(auto& projectStage : DAOManager::getProjectStageDAO().retrieveProject(projectId))
            std::cout << "\t" << projectStage.getId() << " - " << projectStage.getStage().getName() << " - " << ProjectStage::ProjectStageStatusToString(projectStage.getStatus()) << std::endl;
        std::cout << std::endl;
        

        std::cout << "Escolha uma etapa do projeto " << projectId << ":" << std::endl;
        std::cin >> projectStageId;
        std::cout << std::endl;

        std::cout << "Digite 1 para aprovar ou 0 para recusar a etapa " << projectStageId << ":" << std::endl;
        std::cin >> aprove;
        std::cout << std::endl;

        std::cout << "Digite o comentário:" << std::endl;
        std::fflush(stdin);
        std::getline(std::cin, comment);
        std::cout << std::endl;

        FormularioManager fm;
        fm.feedbackForm(projectStageId, comment, aprove == "1");

        std::cout << "Feedback enviado com sucesso" << std::endl;
        std::cout << std::endl;

        std::fflush(stdin);
        std::cout << "Digite qualquer coisa para continuar..." << std::endl;
        std::cin >> ownerId;

    }catch(const char* error){
        std::cout << "Erro: " << error << std::endl;
        std::fflush(stdin);
        std::cout << "Digite qualquer coisa para continuar..." << std::endl;
        std::cin >> ownerId;
        return;
    }

}

void getFeedbackForm(){
    std::string ownerId;
    std::string propertyId;
    std::string projectId;
    std::string projectStageId;
    std::string comment;
    std::string aprove;
    
    try{
        std::cout << "USUÁRIOS DISPONÍVEIS: " << std::endl;
        for(auto& owner : DAOManager::getOwnerDAO().retrieve())
            std::cout << "\t" << owner.getId() << " - " << owner.getName() << std::endl;
        std::cout << std::endl;

        std::cout << "Digite o id do usuário para buscar por suas propriedades: " << std::endl;
        std::cin >> ownerId;
        std::cout << std::endl;

        std::cout << "PROPRIEDADES:" << std::endl;
        for(auto& property : DAOManager::getPropertyDAO().retrieveOwner(ownerId))
            std::cout << "\t" << property.getId() << " - " << property.getName() << " - " << property.getHighway() << " - " << property.getCity() << " - " << property.getState() << " - " << property.getNeighborhood() << std::endl;
        std::cout << std::endl;

        std::cout << "Escolha uma propriedade para procurar por projetos:" << std::endl;
        std::cin >> propertyId;
        std::cout << std::endl;

        std::cout << "PROJETOS:" << std::endl;
        for(auto& project : DAOManager::getProjectDAO().retrieveProperty(propertyId))
            std::cout << "\t" << project.getId() << " - " << project.getName() << " - " << project.getDescription() << std::endl;
        std::cout << std::endl;

        std::cout << "Escolha um projeto para ver todas as suas etapas:" << std::endl;
        std::cin >> projectId;
        std::cout << std::endl;

        std::cout << "ETAPAS DO PROJETO:" << std::endl;
        for(auto& projectStage : DAOManager::getProjectStageDAO().retrieveProject(projectId))
            std::cout << "\t" << projectStage.getId() << " - " << projectStage.getStage().getName() << " - " << ProjectStage::ProjectStageStatusToString(projectStage.getStatus()) << std::endl;
        std::cout << std::endl;
        

        std::cout << "Escolha uma etapa do projeto " << projectId << ":" << std::endl;
        std::cin >> projectStageId;
        std::cout << std::endl;

        FormularioManager fm;
        fm.getFeedbackForm(projectStageId);

        std::cout << std::endl;
        std::fflush(stdin);
        std::cout << "Digite qualquer coisa para continuar..." << std::endl;
        std::cin >> ownerId;

    }catch(const char* error){
        std::cout << "Erro: " << error << std::endl;
        std::cout << "Digite qualquer coisa para continuar..." << std::endl;
        std::cin >> ownerId;
        return;
    }
}

int main(){
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
    #endif

    DAOManager::init(false);

    while(true)
    {
        // LIMPA O TERMINAL
        std::cout << "\033[2J\033[1;1H";

        std::string op;
        std::cout << "Digite 1 para enviar feedback do formulário" << std::endl;
        std::cout << "Digite 2 para ver feedback do formulario" << std::endl;
        std::cout << "Digite 'q' para sair" << std::endl;
        std::cin >> op;
        std::cout << std::endl;

        if(op == "1") sendFeedbackForm();
        else if(op == "2") getFeedbackForm();
        else break;
    }

    return 0;
}