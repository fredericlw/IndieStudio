/*
** EPITECH PROJECT, 2024
    std::vector<Vector3D> obstacles;
    std::array<PlayerData, 4> players;
** GameSaveLoad.cpp
** File description:
** Created by Leo Fabre
*/
#include <Logic/MapComponent.hpp>
#include "GameSaveLoad.hpp"
#include "Entity.hpp"
#include "Manager.hpp"

GameSaveLoad::GameSaveData GameSaveLoad::getSaveData(GameLogicComp &gamelogic)
{
    auto mapEnt = gamelogic.entity->_mgr.getEntByName("maproot");
    auto &mapComp = mapEnt->getComponent<MapComponent>();

    std::vector<Vector3D> obstacles = getObstacles(mapComp);
    std::array<PlayerData, 4> players = getPlayersData(gamelogic);
    GameSaveData save{.obstacles = obstacles, .players = players};
    return save;
}

std::vector<Vector3D> GameSaveLoad::getObstacles(MapComponent &mapComp)
{
    std::vector<Vector3D> res;
    for (const auto &obstacle : mapComp.Obstacles) {
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
        .pos = comp.p1->entity->getComponent<TransformComp>().position,
        .powerUp = comp.p1->getPowerUp(),
        .isAlive = comp.p1->isAlive()
    };
    res[1] = {
        .pos = comp.p2->entity->getComponent<TransformComp>().position,
        .powerUp = comp.p2->getPowerUp(),
        .isAlive = comp.p2->isAlive()
    };
    res[2] = {
        .pos = comp.p3->entity->getComponent<TransformComp>().position,
        .powerUp = comp.p3->getPowerUp(),
        .isAlive = comp.p3->isAlive()
    };
    res[3] = {
        .pos = comp.p4->entity->getComponent<TransformComp>().position,
        .powerUp = comp.p4->getPowerUp(),
        .isAlive = comp.p4->isAlive()
    };

    return res;
}
