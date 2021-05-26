/*
** EPITECH PROJECT, 2024
** ERect.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef ERECT_HPP
#define ERECT_HPP

#include <raylib.h>
#include <Colors.h>

class ERect : public Rectangle {
public:
    ERect(Vector2 size, Vector2 position);
    ~ERect();
    void draw(bool fill, bool outline, Colors fillColor, Colors lineCol);
};

#endif //ERECT_HPP