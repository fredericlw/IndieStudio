/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by Achille Bourgault
*/

#include "Components/GUI/StatusInfoComp.hpp"

StatusInfoComp::StatusInfoComp(Player *player, ERect rect) : _rect(rect)
{
    _player = player;
}

void StatusInfoComp::init()
{
    Component::init();
    transform = &entity->getComponent<TransformComp>();
    if (!transform)
        transform = &entity->addComponent<TransformComp>();
    _rect.x = transform->position.x;
    _rect.y = transform->position.y;
    _rect.width = size.x;
    _rect.height = size.y;
}

void StatusInfoComp::update()
{
    Component::update();
}

void StatusInfoComp::draw()
{
    Component::draw();
    _rect.draw(true, true, _player->getColor(), Gray);
}