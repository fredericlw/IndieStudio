/*
** EPITECH PROJECT, 2023
** bomberman
** File description:
** Created by Adrien Courbebaisse
*/
#include <3D/TransformComp.hpp>
#include <3D/BasicCubeComp.hpp>
#include <Character/MovementComp.hpp>
#include <GUI/LobbyComp.hpp>
#include <utility>
#include <raylib_encap/Window.hpp>
#include "Components/Logic/GameLogicComp.hpp"
#include "Manager.hpp"
#include "Components/Character/PlayerComp.hpp"
#include "Components/GUI/PlayerHUD.hpp"
#include <ECS/Manager.hpp>

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
    //get upper right spawnpos offset from map root entity po
    std::cout << "MAP POSITION IS " << spawnPos << std::endl;
    p1 = SpawnPlayer("Player1", spawnPos,
        entity->getComponent<LobbyComp>().sel1, PlayerOne, Blue);
    spawnPos.x += 24;
    p2 = SpawnPlayer("Player2", spawnPos,
        entity->getComponent<LobbyComp>().sel2, PlayerTwo, Green);
    spawnPos.z += 20;
    p3 = SpawnPlayer("Player3", spawnPos,
        entity->getComponent<LobbyComp>().sel3, PlayerThree, Red);
    spawnPos.x -= 24;
    p4 = SpawnPlayer("Player4", spawnPos,
        entity->getComponent<LobbyComp>().sel4, PlayerFour, LightGray);
}

PlayerComp *GameLogicComp::SpawnPlayer(
    std::string entityName, const Vector3D &pos, EInputType inputType,
    PlayerNum num,
    Colors color
)
{
    auto &myEnt = entity->_mgr.addEntity(std::move(entityName));
    myEnt.addComponent<TransformComp>(pos);
    myEnt.addComponent<BasicCubeComp>(Vector3D::One().Multiply(2)).shouldDraw=
        true;
    myEnt.addGroup(Players);
    return &myEnt.addComponent<PlayerComp>(inputType, num, color);
}

void GameLogicComp::update()
{
    int nb_death = 0;

    if (!p1->isAlive()) nb_death++;
    if (!p2->isAlive()) nb_death++;
    if (!p3->isAlive()) nb_death++;
    if (!p4->isAlive()) nb_death++;
    if (nb_death >= 3) {
        entity->_mgr.loadScene(Manager::GameOverScene);
    }
    Component::update();
}

void GameLogicComp::draw()
{
    Component::draw();
}

void GameLogicComp::SpawnPlayerHUD()
{
    auto winSize = Window::GetWinSize();
    auto size = Vector2D{300, 100};
    auto pos = Vector2D{0, 0};
    auto &hud1 = entity->_mgr.addEntity("P1 hud");
    hud1.addComponent<TransformComp>(pos);
    hud1.addComponent<PlayerHUD>(p1, size);
    hud1.addGroup(GUI);

    pos.x = winSize.x - size.x;
    auto &hud2 = entity->_mgr.addEntity("P2 hud");
    hud2.addComponent<TransformComp>(pos);
    hud2.addComponent<PlayerHUD>(p2, size);
    hud2.addGroup(GUI);

    pos.x = winSize.x - size.x;
    pos.y = winSize.y - size.y;
    auto &hud3 = entity->_mgr.addEntity("P3 hud");
    hud3.addComponent<TransformComp>(pos);
    hud3.addComponent<PlayerHUD>(p3, size);
    hud3.addGroup(GUI);

    pos.x = 0;
    auto &hud4 = entity->_mgr.addEntity("P4 hud");
    hud4.addComponent<TransformComp>(pos);
    hud4.addComponent<PlayerHUD>(p4, size);
    hud4.addGroup(GUI);
}
