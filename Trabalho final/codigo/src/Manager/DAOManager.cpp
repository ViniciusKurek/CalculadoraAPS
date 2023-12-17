#include "DAOManager.h"
#include <iostream>

OwnerDAO DAOManager::ownerDAO = OwnerDAO();
PropertyDAO DAOManager::propertyDAO = PropertyDAO(DAOManager::getOwnerDAO()); // DEPENDÊNCIA
ProjectDAO DAOManager::projectDAO = ProjectDAO(DAOManager::getPropertyDAO()); // DEPENDÊNCIA
StageDAO DAOManager::stageDAO = StageDAO();
ProjectStageDAO DAOManager::projectStageDAO = ProjectStageDAO(DAOManager::getProjectDAO(), DAOManager::getStageDAO()); // DEPENDÊNCIA

void DAOManager::init(bool debug){
    // LIMPA O TERMINAL
    std::cout << "\033[2J\033[1;1H";

    // ETAPAS INICIAIS
    DAOManager::getStageDAO().create("Correção de solo");
    DAOManager::getStageDAO().create("Preparação de solo");
    DAOManager::getStageDAO().create("Fertilização pré-plantio");
    DAOManager::getStageDAO().create("Irrigação");
    DAOManager::getStageDAO().create("Plantio");
    DAOManager::getStageDAO().create("Práticas de cultivo");
    DAOManager::getStageDAO().create("Colheita");

    // PROPRIETÁRIO INICIAL
    DAOManager::getOwnerDAO().create("João da Silva", "joao@email.com", "123456");

    // PROPRIEDADE INICIAL
    DAOManager::getPropertyDAO().create("1", "Fazenda do João", "BR203", "Paraná", "Campo Mourão", "");

    // PROJETO INICIAL
    DAOManager::getProjectDAO().create("1", "Carbono escopo 3 2023/2", "Lorem ipsum dolor sit amet");

    // ETAPAS DO PROJETO INICIAL
    DAOManager::getProjectStageDAO().create("1", "1");
    ProjectStage stage2 = DAOManager::getProjectStageDAO().create("2", "1");
    stage2.setStatus(ProjectStageStatus::ENVIADO);
    DAOManager::getProjectStageDAO().update(stage2);

    ProjectStage stage3 = DAOManager::getProjectStageDAO().create("3", "1");
    stage3.setStatus(ProjectStageStatus::APROVADO);
    DAOManager::getProjectStageDAO().update(stage3);

    ProjectStage stage4 = DAOManager::getProjectStageDAO().create("4", "1");
    stage4.setStatus(ProjectStageStatus::RECUSADO);
    DAOManager::getProjectStageDAO().update(stage4);

    if(debug){

        std::cout << "DEBUG INICIAL DE CRUD" << std::endl << std::endl;

        std::cout << "ETAPAS DISPONÍVEIS:" << std::endl;
        for(Stage stage : DAOManager::getStageDAO().retrieve())
            std::cout << "\t" << stage.getId() << " - " << stage.getName() << std::endl;
        std::cout << std::endl;

        std::cout << "PROPRIETÁRIO CRIADO" << std::endl;
        for(Owner owner : DAOManager::getOwnerDAO().retrieve())
            std::cout << "\t" << owner.getId() << " - " << owner.getName() << " - " << owner.getEmail() << " - " << owner.getPassword() << std::endl;
        std::cout << std::endl;

        std::cout << "PROPRIEDADE CRIADA" << std::endl;
        for(Property property : DAOManager::getPropertyDAO().retrieve())
            std::cout << "\t" << property.getId() << " - " << property.getName() << " - " << property.getHighway() << " - " << property.getCity() << " - " << property.getState() << " - " << property.getNeighborhood() << std::endl;
        std::cout << std::endl;

        std::cout << "PROJETO CRIADO" << std::endl;
        for(Project project : DAOManager::getProjectDAO().retrieve())
            std::cout << "\t" << project.getId() << " - " << project.getName() << " - " << project.getDescription() << std::endl;
        std::cout << std::endl;

        std::cout << "ETAPAS DO PROJETO CRIADAS" << std::endl;
        for(ProjectStage projectStage : DAOManager::getProjectStageDAO().retrieve())
            std::cout << "\t" << projectStage.getId() << " - " << projectStage.getStage().getName() << " - " << ProjectStage::ProjectStageStatusToString(projectStage.getStatus()) << std::endl;

    }
}

OwnerDAO &DAOManager::getOwnerDAO() { return DAOManager::ownerDAO; }
PropertyDAO& DAOManager::getPropertyDAO(){ return DAOManager::propertyDAO; }
ProjectDAO& DAOManager::getProjectDAO(){ return DAOManager::projectDAO; }
StageDAO& DAOManager::getStageDAO(){ return DAOManager::stageDAO; }
ProjectStageDAO& DAOManager::getProjectStageDAO(){ return DAOManager::projectStageDAO; }