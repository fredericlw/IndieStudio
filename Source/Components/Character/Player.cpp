/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by Achille Bourgault
*/

#include <Components/Logic/BombComp.hpp>
#include "Components/Character/Player.hpp"
#include <cmath>
#include <cfenv>
#include <Logic/GameLogicComp.hpp>
#include <BaseValues.h>

Player::Player(
    EInputType e_type, PlayerNum player_num, Colors color
)
    : _eType(e_type),
      _playerNum(player_num),
      _color(color),
      _mc(nullptr),
      _model(nullptr),
      _powerUp(NONE),
      activeBombs(0),
      health(1),
      _maxBombs(1),
      _currentBombFire(BASE_BOMB_FIRE),
      points(0)
{
    _powerUpFilename[NONE] = "";
    _powerUpFilename[FIREUP] = "Assets/Models/powerups/Fire.png";
    _powerUpFilename[SKATE] = "Assets/Models/powerups/Skate.png";
    _powerUpFilename[BOMB_UP] = "Assets/Models/powerups/Bomb_Up.png";
    _powerUpFilename[SOFT_BLOCK_PASS] =
        "Assets/Models/powerups/Soft_Block_Pass.png";
}

void Player::init()
{
    Component::init();
    _mc = &entity->addComponent<MovementComp>(_eType, _playerNum);
    _model = &entity
        ->addComponent<ModelComp>(entity->assets()->PlayerModel, _color);
}

void Player::update()
{
    Component::update();
    if (_mc->getInputModule()->GetButtonPressed(DropBomb)
        && (activeBombs < _maxBombs)) {
        DoDropBomb();
    }
}

void Player::draw()
{
    Component::draw();
}

void Player::DoDropBomb()
{
    activeBombs++;
    auto curPos = entity->getComponent<TransformComp>().position;
    auto &bombEnt = entity->_mgr.addEntity("bomb");
    bombEnt.addComponent<TransformComp>(
        getNearestBlockPos(curPos.Add({1, 0, 1})));
    bombEnt.addComponent<BombComp>(_color, this);
    bombEnt.addGroup(Bombs);
}

Colors Player::getColor() const
{
    return _color;
}

Vector3D Player::getNearestBlockPos(Vector3D pos)
{
    Vector3D res(pos);
    res.Add(Vector3D::One());
    res.y -= 1;
    std::fesetround(FE_TONEAREST);
    res.x = std::nearbyint(pos.x);
    res.z = std::nearbyint(pos.z);

    if (static_cast<int>(res.x) % 2 == 0) {
        if (res.x > pos.x) {
            res.x -= 1;
        } else {
            res.x += 1;
        }
    }
    if (static_cast<int>(res.z) % 2 == 0) {
        if (res.z > pos.z) {
            res.z -= 1;
        } else {
            res.z += 1;
        }
    }
    //todo : this is a quick and ugly (and not working) fix
    res.x -= 1;
    res.z -= 1;
    return res;
}

PowerUpType Player::getPowerUp() const
{
    return _powerUp;
}

void Player::setPowerUp(PowerUpType power_up)
{
    //todo : play powerup activated sound here
    StopPowerup(_powerUp);
    _powerUp = power_up;
    StartPowerup(power_up);
}

void Player::takeDamage()
{
    health--;
    std::cout << "Player hurt" << std::endl;
    if (health <= 0) {
        Die();
        return;
    }
    //todo : play player hurt sound HERE
}

void Player::Die()
{
    std::cout << "PLAYER DED :)" << std::endl;
    //todo : play player died sound HERE
    entity->destroy();
}

void Player::StopPowerup(PowerUpType type)
{
    switch (type) {
    case NONE:
    case ENUM_END:
    case SOFT_BLOCK_PASS:
        return;
    case FIREUP:
        if (_powerUp == FULLFIRE) return;
        _currentBombFire++;
        return;
    case FULLFIRE:
        _currentBombFire = BASE_BOMB_FIRE;
        return;
    case SKATE:
        _mc->setSpeed(BASESPEED);
        return;
    case BOMB_UP:
        _maxBombs--;
        return;
    }
}

void Player::StartPowerup(PowerUpType type)
{
    switch (type) {
    case NONE:
    case ENUM_END:
    case SOFT_BLOCK_PASS:
        return;
    case FIREUP:
        return;
    case FULLFIRE:
        return;
    case SKATE:
        _mc->setSpeed(_mc->getSpeed() * SPEED_MULTIPLIER);
        return;
    case BOMB_UP:
        _maxBombs++;
        return;
    }
}
