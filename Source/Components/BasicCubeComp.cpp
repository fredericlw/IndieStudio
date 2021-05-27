/*
** EPITECH PROJECT, 2024
** BasicCubeComp.cpp
** File description:
** Created by Leo Fabre
*/
#include <raylib.h>
#include <Colors.h>
#include "Components/BasicCubeComp.hpp"
#include "ECS/Entity.hpp"
#include "Components/TransformComp.hpp"
#include "ECS/Manager.hpp"

BasicCubeComp::BasicCubeComp(Vector3D size, Colors cubeCol, Colors wireCol)
    : _size(size), _cubeCol(cubeCol), _wireCol(wireCol)
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