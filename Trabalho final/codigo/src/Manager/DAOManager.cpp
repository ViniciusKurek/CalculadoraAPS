#include "DAOManager.h"

OwnerDAO DAOManager::ownerDAO = OwnerDAO();
PropertyDAO DAOManager::propertyDAO = PropertyDAO(DAOManager::getOwnerDAO()); // DEPENDÊNCIA
ProjectDAO DAOManager::projectDAO = ProjectDAO(DAOManager::getPropertyDAO()); // DEPENDÊNCIA
StageDAO DAOManager::stageDAO = StageDAO();
ProjectStageDAO DAOManager::projectStageDAO = ProjectStageDAO(DAOManager::getProjectDAO(), DAOManager::getStageDAO()); // DEPENDÊNCIA

OwnerDAO& DAOManager::getOwnerDAO(){ return DAOManager::ownerDAO; }
PropertyDAO& DAOManager::getPropertyDAO(){ return DAOManager::propertyDAO; }
ProjectDAO& DAOManager::getProjectDAO(){ return DAOManager::projectDAO; }
StageDAO& DAOManager::getStageDAO(){ return DAOManager::stageDAO; }
ProjectStageDAO& DAOManager::getProjectStageDAO(){ return DAOManager::projectStageDAO; }