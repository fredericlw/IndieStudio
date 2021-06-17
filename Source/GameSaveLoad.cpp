/*
** EPITECH PROJECT, 2024
** GameSaveLoad.cpp
** File description:
** Created by Leo Fabre
*/
#include <Logic/MapComponent.hpp>
#include <fstream>
#include "GameSaveLoad.hpp"
#include "Entity.hpp"
#include "Manager.hpp"
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

GameSaveLoad::GameSaveData GameSaveLoad::getSaveData(GameLogicComp &gamelogic)
{
    auto mapEnt = gamelogic.entity->_mgr.getEntByName("mapRoot");
    auto &mapComp = mapEnt->getComponent<MapComponent>();

    std::vector<Vector3D> obstacles = getObstacles(mapComp);
    std::array<PlayerData, 4> players = getPlayersData(gamelogic);
    GameSaveData save;
    save.obstacles = obstacles;
    save.players = players;
    return save;
}

std::vector<Vector3D> GameSaveLoad::getObstacles(MapComponent &mapComp)
{
    auto &obstacles = mapComp.entity->_mgr.getEntitiesInGroup(Obstacles);
    std::vector<Vector3D> res;
    res.reserve(obstacles.size());
    for (const auto &obstacle : obstacles) {
        res.emplace_back(obstacle->getComponent<TransformComp>().position);
    }
    return res;
}

std::array<GameSaveLoad::PlayerData, 4> GameSaveLoad::getPlayersData(
    GameLogicComp &comp
)
{
    std::array<PlayerData, 4> res;
    res[0] = {
        comp.p1->entity->getComponent<TransformComp>().position,
        comp.p1->getPowerUp(),
        comp.p1->getScore(),
        comp.p1->isAlive()
    };
    res[1] = {
        comp.p2->entity->getComponent<TransformComp>().position,
        comp.p2->getPowerUp(),
        comp.p2->getScore(),
        comp.p2->isAlive()
    };
    res[2] = {
        comp.p3->entity->getComponent<TransformComp>().position,
        comp.p3->getPowerUp(),
        comp.p3->getScore(),
        comp.p3->isAlive()
    };
    res[3] = {
        comp.p4->entity->getComponent<TransformComp>().position,
        comp.p4->getPowerUp(),
        comp.p4->getScore(),
        comp.p4->isAlive()
    };

    return res;
}

std::shared_ptr<GameSaveLoad::GameSaveData> GameSaveLoad::loadDataFromSaveFile()
{
    auto res = std::make_shared<GameSaveData>();
    std::ifstream ifs("./savedGame");
    if (!ifs.good()) {
        std::cerr << "NO SAVE FILE FOUND !!!" << std::endl;
        return nullptr;
    }
    boost::archive::text_iarchive iar(ifs);
    iar >> *res;
    return res;
}

void GameSaveLoad::SaveGameToFile(GameLogicComp &gamelogic)
{
    std::ofstream ofs("./savedGame", std::ios_base::trunc);
    if (!ofs.good()) {
        std::cerr << "COULDN'T CREATE OR OVERWRITE SAVE FILE" << std::endl;
        return;
    }
    boost::archive::text_oarchive outAr(ofs);
    outAr << getSaveData(gamelogic);
}
