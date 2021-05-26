/*
** EPITECH PROJECT, 2024
** ECube.cpp
** File description:
** Created by Leo Fabre
*/
#include <raylib_encap/Math/Vector3D.hpp>
#include <Colors.h>
#include "ECube.hpp"

ECube::ECube()
{
}

ECube::~ECube()
{
}

void ECube::draw(Vector3D pos, Vector3D _size, Colors cubeColor, Colors wiresColor)
{
    DrawCube(pos, _size.x, _size.y, _size.z, GetRaylibColor(cubeColor));
    DrawCubeWires(pos, _size.x, _size.y, _size.z, GetRaylibColor(wiresColor));
}
