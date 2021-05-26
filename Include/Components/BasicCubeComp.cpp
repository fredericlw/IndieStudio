/*
** EPITECH PROJECT, 2024
** BasicCubeComp.cpp
** File description:
** Created by Leo Fabre
*/
#include <raylib.h>
#include <Colors.h>
#include "BasicCubeComp.hpp"
#include "ECS/Entity.hpp"
#include "TransformComp.hpp"
#include "ECS/Manager.hpp"

BasicCubeComp::BasicCubeComp(Vector3D size)
    : _size(size)
{
}

BasicCubeComp::~BasicCubeComp()
{
}

void BasicCubeComp::init()
{
    Component::init();
    transform = &entity->getComponent<TransformComp>();
    if (!transform)
        transform = &entity->addComponent<TransformComp>();
}

void BasicCubeComp::update()
{
    Component::update();
}

void BasicCubeComp::draw()
{
    Component::draw();
    entity->_mgr.MainCam.Begin3D();
    _cube.draw(transform->position, _size, Colors::Red, Colors::White);
    entity->_mgr.MainCam.End3D();
}