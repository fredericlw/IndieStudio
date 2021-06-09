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
    : _rect(ERect{size,{0, 0}}),
    _player(player), _lastPowerup(player->getPowerUp()), _PowerUpDisplay(nullptr)
{
//    std::cout << "file : " << _player->_powerUpFilename[_player->getPowerUp()] << std::endl;

    /*
     *     if (_player->getPowerUp() != PowerUp::NONE)
        _iconPowerup = ESprite(_player->_powerUpFilename[_player->getPowerUp()]);
     */
}

void PlayerHUD::init()
{
    Component::init();
    transform = &entity->getComponent<TransformComp>();
    if (!transform)
        transform = &entity->addComponent<TransformComp>();
    _rect.x = transform->position.x;
    _rect.y = transform->position.y;
}

void PlayerHUD::update()
{
    auto powerUp = _player->getPowerUp();
    Vector2D pos(0, 0);

    if (powerUp != _lastPowerup) {
        if (_PowerUpDisplay != nullptr)
            _PowerUpDisplay->destroy();
        _PowerUpDisplay = &entity->_mgr.addEntity("PowerUpDisplay");
        _PowerUpDisplay->addGroup(GUI);
        _PowerUpDisplay->addComponent<TransformComp>(pos);
        _PowerUpDisplay->addComponent<Sprite2D>(_player->_powerUpFilename[_player->getPowerUp()]);
        _lastPowerup = powerUp;
    }
    Component::update();
}

void PlayerHUD::draw()
{
    Component::draw();
    _rect.draw(true, true, _player->getColor(), Gray);
}