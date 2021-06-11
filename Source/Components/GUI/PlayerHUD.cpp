/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by Achille Bourgault
*/

#include "Entity.hpp"
#include <ECS/Manager.hpp>
#include <Components/3D/BasicCubeComp.hpp>
#include <raylib_encap/Math/Vector2D.hpp>
#include <GUI/AnimatedSprite.hpp>
#include "Components/Components.h"
#include "Components/GUI/PlayerHUD.hpp"

PlayerHUD::PlayerHUD(PlayerComp *player, Vector2D size)
    : _backgroundRect(ERect{size,{0, 0}}),
    _player(player), _lastPowerup(player->getPowerUp()), _PowerUpDisplay(nullptr), _ScoreDisplay(
        nullptr)
{
//    std::cout << "file : " << _player->_powerUpFilename[_player->getPowerUp()] << std::endl;

    /*
     *     if (_player->getPowerUp() != PowerUpType::NONE)
        _iconPowerup = ESprite(_player->_powerUpFilename[_player->getPowerUp()]);
     */
}

void PlayerHUD::init()
{
    Component::init();
    transform = &entity->getComponent<TransformComp>();
    if (!transform)
        transform = &entity->addComponent<TransformComp>();
    _backgroundRect.x = transform->position.x;
    _backgroundRect.y = transform->position.y;
    Vector3D position = transform->position;
    position.x += _backgroundRect.width / 2;
    auto textEntity = &entity->_mgr.addEntity("textEntity");
    textEntity->addComponent<TransformComp>(position.Add(Vector2D {0, 10}));
    _ScoreDisplay = &textEntity->addComponent<TextComp>(std::to_string(_player->getScore()), Black);
    textEntity->addGroup(GUI_TOP);
}

void PlayerHUD::update()
{
    Component::update();
    if (!_player) {
        //TODO : show player dead sprite instead of powerup sprite
        return;
    }
    auto powerUp = _player->getPowerUp();

    if (powerUp != _lastPowerup) {
        if (_PowerUpDisplay != nullptr)
            _PowerUpDisplay->destroy();
        _PowerUpDisplay = &entity->_mgr.addEntity("PowerUpDisplay");
        _PowerUpDisplay->addGroup(GUI);
        _PowerUpDisplay->addComponent<TransformComp>(transform->position);
        _PowerUpDisplay->addComponent<Sprite2D>(*getPowerupSprite(_player->getPowerUp()));
        _lastPowerup = powerUp;
    }
    _ScoreDisplay->_text = std::to_string(_player->getScore());
}

void PlayerHUD::draw()
{
    Component::draw();
    _backgroundRect.draw(true, true, _player->getColor(), Gray);
}

ESprite *PlayerHUD::getPowerupSprite(PowerUpType type)
{
    switch (type) {
    case FIREUP:
        return &entity->assets()->FireUpSprite;
    case FULLFIRE:
        return &entity->assets()->FullFireSprite;
    case SKATE:
        return &entity->assets()->SkateSprite;
    case BOMB_UP:
        return &entity->assets()->BombUpSprite;
    case SOFT_BLOCK_PASS:
        return &entity->assets()->SoftBlockPassSprite;
    default:
        std::cerr << "BAD POWERUP, SPRITE WILL BE NULL" << std::endl;
        ESprite *res = nullptr;
        return res;
    }
}
