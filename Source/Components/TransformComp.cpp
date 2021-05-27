/*
** EPITECH PROJECT, 2024
** TransformComp.cpp
** File description:
** Created by Leo Fabre
*/
#include "Components/3D/TransformComp.hpp"

TransformComp::TransformComp(float x, float y, float z)
    : position(x, y, z)
{
    position.x = x;
    position.y = y;
    position.z = z;
}

void TransformComp::update()
{
}

TransformComp::TransformComp(const Vector3D &Position)
    : position(Position)
{
}
