/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by Achille Bourgault
*/

#include <Component.hpp>
#include "BombComp.hpp"
#include "Manager.hpp"

BombComp::BombComp(Colors color) : _color(color), _transform(nullptr),
    _cube(nullptr)
{
}

void BombComp::init()
{
    Component::init();
    _transform = &entity->getComponent<TransformComp>();
    if (!_transform)
        _transform = &entity->addComponent<TransformComp>();
    _cube = &entity->addComponent<BasicCubeComp>(Vector3D::One().Multiply(2));
}

void BombComp::update()
{
    Component::update();
}

void BombComp::draw()
{
    Component::draw();
}

