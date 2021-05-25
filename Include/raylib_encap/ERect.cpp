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

void ERect::draw(bool fill, bool outline, Color fillColor, Color lineCol)
{
    if (fill)
        DrawRectangleRec(*this, fillColor);
    if (outline)
        DrawRectangleLines((int) x, (int) y, (int) width, (int) height,
            lineCol);
}
