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

class Player : public Component {
    public:
    Player(
        EInputType e_type, PlayerNum player_num, Colors color
    );
    void init() override;
    void update() override;
    void draw() override;
    private:
    EInputType _eType;
    PlayerNum _playerNum;
    Colors _color;
    MovementComp *_mc;
    ModelComp *_model;
};

#endif //BOMBERMAN_PLAYER_HPP