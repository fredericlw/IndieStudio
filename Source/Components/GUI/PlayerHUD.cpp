/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by Achille Bourgault
*/

#include <ECS/Manager.hpp>
#include <Components/3D/BasicCubeComp.hpp>
#include <raylib_encap/Math/Vector2D.hpp>
#include <GUI/AnimatedSprite.hpp>
#include "Components/Components.h"
#include "Components/GUI/PlayerHUD.hpp"

PlayerHUD::PlayerHUD(Player *player, Vector2D size)
    : _backgroundRect(ERect{size,{0, 0}}),
    _player(player), _lastPowerup(player->getPowerUp()), _PowerUpDisplay(nullptr)
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
        _PowerUpDisplay->addComponent<Sprite2D>(_player->_powerUpFilename[_player->getPowerUp()]);
        _lastPowerup = powerUp;
    }
    //TODO : Show _player->score
}

void PlayerHUD::draw()
{
    Component::draw();
    _backgroundRect.draw(true, true, _player->getColor(), Gray);
}