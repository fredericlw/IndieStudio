/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by Achille Bourgault
*/

#ifndef BOMBERMAN_PLAYER_HPP
#define BOMBERMAN_PLAYER_HPP

#include <Keys.h>
#include <Character/MovementComp.hpp>
#include <3D/ModelComp.hpp>
#include "Entity.hpp"
#include "Manager.hpp"
#include <ctime>
#include <GUI/PauseMenuComp.hpp>
#include <3D/FramesModel.hpp>
#include "powerup.hpp"

class PlayerComp : public Component {
public:
    PlayerComp(
        EInputType e_type, PlayerNum player_num, Colors color
    );
    void init() override;
    void update() override;
    void draw() override;
    Colors getColor() const;
    [[nodiscard]] PowerUpType getPowerUp() const;
    std::map<PowerUpType, std::string> _powerUpFilename;
    int activeBombs;
    void setScore(int value);
private:
    EInputType _eType;
    PlayerNum _playerNum;
    Colors _color;
    MovementComp *_mc;
//    ModelComp *_model;
    FramesModel *_model;
    PowerUpType _powerUp;
    void DoDropBomb();
public:
    Vector3D getNearestBlockPos(Vector3D pos);
    int getScore() const;
    void addScore(int value);
    void takeDamage();
    int health;
    void Die();
public:
    void setPowerUp(PowerUpType power_up, bool doAddScore = true);
    bool isAlive() const;
    void killOnLoad();
    PlayerNum getPlayerNum() const;
    int _currentBombFire;
private:
    int score;
    int _maxBombs;
    void StopPowerup(PowerUpType type);
    void StartPowerup(PowerUpType type);
    bool _alive;
    PauseMenuComp *_pmc;

    //todo: refactor IA stuff
    void IAupdate();
    std::vector<std::vector<char>> map;

};

#endif //BOMBERMAN_PLAYER_HPP