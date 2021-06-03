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
#include <ctime>
#include <3D/ModelComp.hpp>

class BombComp : public Component {
public:
    BombComp(Colors color);
    void init() override;
    void update() override;
    void draw() override;
private:
    void explode();
    std::time_t spawnTime{};
    TransformComp *_transform;
    BasicCubeComp *_cube;
    ModelComp *model;
    Colors _color;

    Model bombModel;
    Texture2D texture;
};

#endif //BOMBERMAN_BOMBCOMP_HPP
