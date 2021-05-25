/*
** EPITECH PROJECT, 2024
** RectCollider.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef RECTCOLLIDER_HPP
#define RECTCOLLIDER_HPP

class RectCollider {
public:
    static bool CheckPointInRect(Vector2 Point, Rectangle Rect);
    static bool CheckRectOverlap(Rectangle rec1, Rectangle rec2);
    static bool CheckMouseInRect(Rectangle Rect);
};

#endif //RECTCOLLIDER_HPP