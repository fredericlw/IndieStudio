/*
** EPITECH PROJECT, 2024
** ECube.cpp
** File description:
** Created by Leo Fabre
*/
#include <raylib_encap/Math/Vector3D.hpp>
#include <Colors.h>
#include "raylib_encap/ECube.hpp"

ECube::ECube()
    : _pos(Vector3D::Zero()),
      _size(Vector3D::One())
{
}

ECube::~ECube()
{
}

void ECube::draw(
    const Vector3D &pos, const Vector3D &size, Colors cubeColor,
    Colors wiresColor
)
{
    _size = size;
    _pos = pos;
    DrawCube(pos, _size.x, _size.y, _size.z, GetRaylibColor(cubeColor));
    DrawCubeWires(pos, _size.x, _size.y, _size.z, GetRaylibColor(wiresColor));
}

//region get/set

const Vector3D &ECube::getPos() const
{
    return _pos;
}

void ECube::setPos(const Vector3D &pos)
{
    _pos = pos;
}

const Vector3D &ECube::getSize() const
{
    return _size;
}

void ECube::setSize(const Vector3D &size)
{
    _size = size;
}

//endregion

ECube::ECube(const Vector3D &pos, const Vector3D &size)
    :
    _pos(pos),
    _size(size)
{
}

ECube::ECube(BoundingBox box)
    : _pos(box.min.x, box.min.y, box.min.z),
      _size(
          box.max.x - box.min.x,
          box.max.y - box.min.y,
          box.max.z - box.min.z
      )
{
}


