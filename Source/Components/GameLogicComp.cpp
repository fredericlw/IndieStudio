/*
** EPITECH PROJECT, 2023
** bomberman
** File description:
** Created by Adrien Courbebaisse
*/
#include <3D/TransformComp.hpp>
#include <3D/ModelComp.hpp>
#include <3D/BasicCubeComp.hpp>
#include <Character/MovementComp.hpp>
#include <GUI/LobbyComp.hpp>
#include <utility>
#include <raylib_encap/Window.hpp>
#include "GameLogicComp.hpp"
#include "Manager.hpp"
#include "Player.hpp"
#include "Components/GUI/StatusInfoComp.hpp"

void GameLogicComp::init()
{
    Component::init();
    SpawnPlayers();
    SpawnPlayerHUD();
}

void GameLogicComp::SpawnPlayers()
{
    auto spawnPos = entity->_mgr.getEntByName(
        "mapRoot")->getComponent<TransformComp>().position;
    //get upper right spawnpos offset from map root entity pos
    spawnPos.z -= 33;
    spawnPos.y += 2;
    spawnPos.x -= 13;
    std::cout << "MAP POSITION IS " << spawnPos<< std::endl;
    p1 = SpawnPlayer(std::string("Player 1"), spawnPos,
        entity->getComponent<LobbyComp>().sel1, PlayerOne, Blue);
    spawnPos.x += 24;
    p2 = SpawnPlayer(std::string("Player 2"), spawnPos,
        entity->getComponent<LobbyComp>().sel2, PlayerTwo, Green);
    spawnPos.z += 20;
    p3 =SpawnPlayer(std::string("Player 3"), spawnPos,
        entity->getComponent<LobbyComp>().sel3, PlayerThree, Red);
    spawnPos.x -= 24;
    p4 =SpawnPlayer(std::string("Player 4"), spawnPos,
        entity->getComponent<LobbyComp>().sel4, PlayerFour, LightGray);
}

Player *GameLogicComp::SpawnPlayer(
    std::string entityName, const Vector3D &pos, EInputType inputType,
    PlayerNum num,
    Colors color
)
{
    auto &myEnt = entity->_mgr.addEntity(std::move(entityName));
    myEnt.addComponent<TransformComp>(pos);
    myEnt.addComponent<BasicCubeComp>(Vector3D::One().Multiply(2));
    return &myEnt.addComponent<Player>(inputType, num, color);
}

void GameLogicComp::update()
{
    Component::update();
}

void GameLogicComp::draw()
{
    Component::draw();
}

void GameLogicComp::SpawnPlayerHUD()
{
    auto winSize = Window::GetWinSize();
    auto size = Vector2D{300, 50};
    auto pos = Vector2D{0,0};
    auto &hud1 = entity->_mgr.addEntity("P1 hud");
    hud1.addComponent<TransformComp>(pos);
    hud1.addComponent<StatusInfoComp>(p1, size);
}
