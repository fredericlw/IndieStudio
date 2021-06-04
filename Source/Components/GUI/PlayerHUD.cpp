/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by Achille Bourgault
*/

#include "Components/GUI/PlayerHUD.hpp"

PlayerHUD::PlayerHUD(Player *player, Vector2D size)
    : _rect(ERect{size,{0, 0}}),
    _player(player)
{

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
    Component::update();
}

void PlayerHUD::draw()
{
    Component::draw();
    _rect.draw(true, true, _player->getColor(), Gray);
}