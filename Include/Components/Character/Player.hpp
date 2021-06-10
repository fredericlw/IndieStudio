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
#include "powerup.hpp"

class Player : public Component {
public:
    Player(
        EInputType e_type, PlayerNum player_num, Colors color
    );
    void init() override;
    void update() override;
    void draw() override;
    Colors getColor() const;
    [[nodiscard]] PowerUpType getPowerUp() const;
    std::map<PowerUpType, std::string> _powerUpFilename;
    int activeBombs;
private:
    EInputType _eType;
    PlayerNum _playerNum;
    Colors _color;
    MovementComp *_mc;
    ModelComp *_model;
    PowerUpType _powerUp;
    void DoDropBomb();
public:
    Vector3D getNearestBlockPos(Vector3D pos);
    int points;
    void takeDamage();
    int health;
    void Die();
public:
    void setPowerUp(PowerUpType power_up);
    int _currentBombFire;
private:
    int _maxBombs;
    void StopPowerup(PowerUpType type);
    void StartPowerup(PowerUpType type);
};

#endif //BOMBERMAN_PLAYER_HPP