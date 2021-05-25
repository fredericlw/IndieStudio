/*
** EPITECH PROJECT, 2024
** RectCollider.cpp
** File description:
** Created by Leo Fabre
*/
#include <raylib.h>
#include "RectCollider.hpp"

RectCollider::~RectCollider()
{
}

bool RectCollider::CheckPointInRect(Vector2 Point, Rectangle Rect)
{
    return CheckCollisionPointRec(Point, Rect);
}

bool RectCollider::CheckMouseInRect( Rectangle Rect)
{
    return CheckCollisionPointRec(GetMousePosition(), Rect);
}

bool RectCollider::CheckRectOverlap(Rectangle rec1, Rectangle rec2)
{
    return CheckCollisionRecs(rec1, rec2);
}
