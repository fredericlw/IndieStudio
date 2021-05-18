/*
** EPITECH PROJECT, 2024
** PositionComponent.cpp
** File description:
** Created by Leo Fabre
*/
#include "PositionComponent.hpp"

int PositionComponent::x()
{
    return xpos;
}

int PositionComponent::y()
{
    return ypos;
}

void PositionComponent::setPos(int x, int y)
{
    xpos = x;
    ypos = y;
}

void PositionComponent::update()
{
}

int PositionComponent::z()
{
    return zpos;
}
