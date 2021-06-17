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
#include <Logic/BombComp.hpp>
#include <Logic/PowerUpComp.hpp>

GameSaveData GameSaveLoad::getSaveData(GameLogicComp &gamelogic)
{
    auto mapEnt = gamelogic.entity->_mgr.getEntByName("mapRoot");
    auto &mapComp = mapEnt->getComponent<MapComponent>();

    GameSaveData save{
        getObstacles(mapComp),
        getPlayersData(gamelogic),
        getBombsData(gamelogic),
        getPowerUpsData(gamelogic)
    };
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

std::array<PlayerData, 4> GameSaveLoad::getPlayersData(
    GameLogicComp &comp
)
{
    std::array<PlayerData, 4> res;
    res[0] = {
        comp.p1->entity->getComponent<TransformComp>().position,
        comp.p1->getPowerUp(),
        comp.p1->getScore(),
        comp.p1->isAlive(),
        comp.p1->activeBombs
    };
    res[1] = {
        comp.p2->entity->getComponent<TransformComp>().position,
        comp.p2->getPowerUp(),
        comp.p2->getScore(),
        comp.p2->isAlive(),
        comp.p4->activeBombs
    };
    res[2] = {
        comp.p3->entity->getComponent<TransformComp>().position,
        comp.p3->getPowerUp(),
        comp.p3->getScore(),
        comp.p3->isAlive(),
        comp.p4->activeBombs
    };
    res[3] = {
        comp.p4->entity->getComponent<TransformComp>().position,
        comp.p4->getPowerUp(),
        comp.p4->getScore(),
        comp.p4->isAlive(),
        comp.p4->activeBombs
    };

    return res;
}

GameSaveData GameSaveLoad::loadDataFromSaveFile()
{
    GameSaveData res;
    std::ifstream ifs("./savedGame");
    if (!ifs.good()) {
        std::cerr << "NO SAVE FILE FOUND !!!" << std::endl;
    }
    boost::archive::text_iarchive iar(ifs);
    iar >> res;
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

std::vector<BombData> GameSaveLoad::getBombsData(GameLogicComp &gl)
{
    std::vector<BombData> res;
    auto &bombs = gl.entity->_mgr.getEntitiesInGroup(Bombs);
    res.reserve(bombs.size());
    for (const auto &bombEnt : bombs) {
        auto &bomb = bombEnt->getComponent<BombComp>();
        auto &pos = bombEnt->getComponent<TransformComp>().position;
        res.emplace_back(
            BombData{bomb.timeAlive, pos, bomb.getOwner()->getPlayerNum()});
    }
    return res;
}

std::vector<PowerUpData> GameSaveLoad::getPowerUpsData(GameLogicComp &comp)
{

    std::vector<PowerUpData> res;
    auto &PUs = comp.entity->_mgr.getEntitiesInGroup(PowerUps);
    res.reserve(PUs.size());
    for (const auto &puEnt : PUs) {
        auto &puComp = puEnt->getComponent<PowerUpComp>();
        auto &pos = puEnt->getComponent<TransformComp>().position;
        res.emplace_back(PowerUpData{pos, puComp.type});
    }
    return res;
}
