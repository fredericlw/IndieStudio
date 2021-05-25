/*
** EPITECH PROJECT, 2024
** ERect.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef ERECT_HPP
#define ERECT_HPP

#include <raylib.h>

class ERect : public Rectangle {
public:
    ERect(Vector2 size, Vector2 position);
    ~ERect();
    void draw(bool fill, bool outline, Color fillColor, Color lineCol);
};

#endif //ERECT_HPP