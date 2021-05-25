/*
** EPITECH PROJECT, 2024
** ERect.cpp
** File description:
** Created by Leo Fabre
*/
#include "ERect.hpp"

ERect::ERect(Vector2 size, Vector2 position)
    : Rectangle({position.x, position.y, size.x, size.y})
{
}

ERect::~ERect()
{
}
