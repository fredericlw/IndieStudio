/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by Achille Bourgault
*/

#ifndef BOMBCOMP
#define BOMBCOMP

#include <3D/TransformComp.hpp>
#include <3D/BasicCubeComp.hpp>
#include "Component.hpp"


class BombComp : public Component {
    public:
    BombComp(Colors color);
    BombComp(TransformComp *transform);
    void init() override;
    void update() override;
    void draw() override;
    private:
    TransformComp *_transform;
    BasicCubeComp *_cube;
    Colors _color;
};

#endif //BOMBERMAN_BOMBCOMP_HPP
