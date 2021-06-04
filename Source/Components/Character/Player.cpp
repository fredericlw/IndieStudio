/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by Achille Bourgault
*/

#include <Components/Logic/BombComp.hpp>
#include "Components/Character/Player.hpp"

Player::Player(
    EInputType e_type, PlayerNum player_num, Colors color
)
    : _eType(e_type),
      _playerNum(player_num),
      _color(color),
      _mc(nullptr),
      _model(nullptr),
      droppedBombs(0),
      bombCoolDown(3)
{
}

void Player::init()
{
    Component::init();
    _mc = &entity->addComponent<MovementComp>(_eType, _playerNum);
    _model =
        &entity->addComponent<ModelComp>("./rsc/Models/mrfixit.iqm", _color,
            .5);
    _model->rotate({90, 0, 0});
}

void Player::update()
{
    Component::update();
    if (_mc->getInputModule()->GetButtonPressed(DropBomb)
    && (std::difftime(std::time(nullptr), lastBombTime) > bombCoolDown || droppedBombs == 0)) {
        DoDropBomb();
    }
}

void Player::draw()
{
    Component::draw();
}

void Player::DoDropBomb()
{
    lastBombTime = std::time(nullptr);
    droppedBombs++;
    auto curPos = entity->getComponent<TransformComp>().position;
    auto &bombEnt = entity->_mgr.addEntity("bomb");
    bombEnt.addComponent<TransformComp>(curPos);
    bombEnt.addComponent<BombComp>(_color);
    bombEnt.addGroup(Bombs);
}

Colors Player::getColor() const
{
    return _color;
}
