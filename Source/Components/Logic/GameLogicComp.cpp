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
#include <GUI/GameOverComp.hpp>
#include <GameSaveLoad.hpp>
#include <Logic/BombComp.hpp>
#include <Logic/PowerUpComp.hpp>

void GameLogicComp::init()
{
    entity->SetDontDestroyOnLoad(true);
    Component::init();
    if (entity->assets()->loadGame) {
        LoadPlayers();
        LoadBombs();
        LoadPowerups();
    } else {
        SpawnPlayers();
    }
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

void GameLogicComp::LoadPlayers()
{
    auto players = GameSaveLoad::loadDataFromSaveFile().players;

    p1 = loadPlayer("Player1", players[0],
        entity->getComponent<LobbyComp>().sel1, PlayerOne, Blue);

    p2 = loadPlayer("Player1", players[1],
        entity->getComponent<LobbyComp>().sel2, PlayerTwo, Green);

    p3 = loadPlayer("Player3", players[2],
        entity->getComponent<LobbyComp>().sel3, PlayerThree, Red);

    p4 = loadPlayer("Player4", players[3],
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
    myEnt.addComponent<BasicCubeComp>(Vector3D::One().Multiply(2)).shouldDraw =
        true;
    myEnt.addGroup(Players);
    return &myEnt.addComponent<PlayerComp>(inputType, num, color);
}

void GameLogicComp::update()
{
    switch (gameState) {
    case Game:
        update_game();
        break;
    case GameOver:
        update_gameOver();
        break;
    }
    Component::update();
}

void GameLogicComp::update_game()
{
    int nb_death = 0;

    if (!p1->isAlive()) nb_death++;
    if (!p2->isAlive()) nb_death++;
    if (!p3->isAlive()) nb_death++;
    if (!p4->isAlive()) nb_death++;
    if (nb_death >= 3) {
        //get player points
        playerStates[0] = p1->isAlive();
        playerStates[1] = p2->isAlive();
        playerStates[2] = p3->isAlive();
        playerStates[3] = p4->isAlive();
        gameState = GameOver;
        auto &ent = entity->_mgr.addEntity("gameoverEnt");
        auto &comp = ent.addComponent<GameOverComp>(playerStates);
        comp.DoGameOver();
    }
}

void GameLogicComp::draw()
{
    Component::draw();
}

void GameLogicComp::SpawnPlayerHUD()
{
    auto winSize = Window::GetWinSize();
    auto size = Vector2D{225, 64};
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

void GameLogicComp::update_gameOver()
{
    //this function may be useless
}

PlayerComp *GameLogicComp::loadPlayer(
    const char *entName, PlayerData &data, EInputType InputType,
    PlayerNum num, Colors color
)
{
    auto &myEnt = entity->_mgr.addEntity(entName);
    myEnt.addComponent<TransformComp>(data.pos);
    myEnt.addComponent<BasicCubeComp>(Vector3D::One().Multiply(2)).shouldDraw =
        false;
    myEnt.addGroup(Players);
    auto playerComp = &myEnt.addComponent<PlayerComp>(InputType, num, color);
    playerComp->setScore(data.score);
    playerComp->setPowerUp(data.powerUp);
    if (!data.isAlive) {
        playerComp->killOnLoad();
    }
    return playerComp;
}

void GameLogicComp::LoadBombs()
{
    auto bombs = GameSaveLoad::loadDataFromSaveFile().bombs;
    if (bombs.empty()) return;
    for (const auto &bomb : bombs) {
        std::cout << "bomb data : " << bomb << std::endl;
        auto player = getPlayerByNum(bomb.owner);
        auto &bombEnt = entity->_mgr.addEntity("bomb");
        bombEnt.addComponent<TransformComp>(bomb.pos);
        auto &bc = bombEnt.addComponent<BombComp>(player->getColor(), player);
        bc.timeAlive = bomb.timeAlive;
        bombEnt.addGroup(Bombs);
    }
}

void GameLogicComp::LoadPowerups()
{
    auto powerups = GameSaveLoad::loadDataFromSaveFile().powerUps;
    if (powerups.empty()) return;
    for (const auto &powerup : powerups) {
        auto &puEnt = entity->_mgr.addEntity("powerup");
        puEnt.addComponent<TransformComp>(powerup.pos);
        puEnt.addComponent<PowerUpComp>(powerup.type);
    }
}

PlayerComp *GameLogicComp::getPlayerByNum(PlayerNum num) const
{
    switch (num) {
    case PlayerOne:
        return p1;
    case PlayerTwo:
        return p2;
    case PlayerThree:
        return p3;
    case PlayerFour:
        return p4;
    default:
        std::cerr << "ERROR : BAD PLAYERNUM !" << std::endl;
        return nullptr;
    }
}
