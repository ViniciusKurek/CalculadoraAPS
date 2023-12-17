#pragma once

#include "../DAO/OwnerDAO.h"
#include "../DAO/PropertyDAO.h"
#include "../DAO/ProjectDAO.h"
#include "../DAO/StageDAO.h"
#include "../DAO/ProjectStageDAO.h"

/**
 * Nesta classe, não podemos usar instâncias diferentes de DAOs, pois cada DAO
 * tem o seu próprio repositório de dados, que é usado também em outros DAOs.
 * Veja na implementação essa dependência.
 * 
 * Dessa forma, em qualquer lugar da aplicação que eu chamar um DAO, eu estarei trabalhando
 * com os mesmos dados (mesmo repositório) para todo o projeto.
 * 
 * Na vida real, com banco de dados, daria para fazer DAOs diferentes, pois não teríamos a necessidade
 * de armazenar os dados em memória. Então cada DAO poderia ter sua própria conexão com o banco de dados.
*/
class DAOManager{

private:
    static OwnerDAO ownerDAO;
    static PropertyDAO propertyDAO;
    static ProjectDAO projectDAO;
    static StageDAO stageDAO;
    static ProjectStageDAO projectStageDAO;

public:
    static void init(bool debug);
    static OwnerDAO& getOwnerDAO();
    static PropertyDAO& getPropertyDAO();
    static ProjectDAO& getProjectDAO();
    static StageDAO& getStageDAO();
    static ProjectStageDAO& getProjectStageDAO();

};