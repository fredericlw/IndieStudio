/*
** EPITECH PROJECT, 2024
** BasicCubeComp.cpp
** File description:
** Created by Leo Fabre
*/
#include <raylib.h>
#include <Colors.h>
#include "Components/3D/BasicCubeComp.hpp"
#include "ECS/Entity.hpp"
#include "Components/3D/TransformComp.hpp"
#include "ECS/Manager.hpp"
#include <cmath>        // std::abs

BasicCubeComp::BasicCubeComp(
    Vector3D size, Colors cubeCol, Colors wireCol, Vector3D offset
)
    : _size(size),
      _cubeCol(cubeCol),
      _wireCol(wireCol),
      _offset(offset)
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

const ECube &BasicCubeComp::getCube() const
{
    return _cube;
}

void BasicCubeComp::draw()
{
    Component::draw();
    entity->_mgr.MainCam.Begin3D();
    _cube.draw(transform->position.Add(_offset), _size, _cubeCol, _wireCol);
    entity->_mgr.MainCam.End3D();
}

void BasicCubeComp::stickCube(Vector3D &nextpos, const ECube &colisionCube)
{
    const Vector3D &colisionPos = colisionCube.getPos();
    float diffx = colisionPos.x - nextpos.x;
    float diffz = colisionPos.z - nextpos.z;

    if (std::abs(diffx) > std::abs(diffz)) {
        if (diffx < 0)
            nextpos.x =
                colisionPos.x + (colisionCube.getSize().x / 2) + _size.x / 2;
        else
            nextpos.x =
                colisionPos.x - (colisionCube.getSize().x / 2) - _size.x / 2;
    } else {
        if (diffz < 0)
            nextpos.z =
                colisionPos.z + (colisionCube.getSize().z / 2) + _size.z / 2;
        else
            nextpos.z =
                colisionPos.z - (colisionCube.getSize().z / 2) - _size.z / 2;
    }
}

