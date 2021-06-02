/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by Achille Bourgault
*/

#include "Player.hpp"

Player::Player(
    EInputType e_type, PlayerNum player_num, Colors color
)
    : _eType(e_type),
      _playerNum(player_num),
      _color(color)
{
}

void Player::init()
{
    Component::init();
    _mc = &entity->addComponent<MovementComp>(_eType, _playerNum);

    _model = &entity->addComponent<ModelComp>("./rsc/Models/mrfixit.iqm", _color,
        0.77);
    _model->rotate({90, 0, 0});
}

void Player::update()
{
    Component::update();
}

void Player::draw()
{
    Component::draw();
}
