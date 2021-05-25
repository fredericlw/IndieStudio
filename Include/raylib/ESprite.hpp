/*
** EPITECH PROJECT, 2024
** ESprite.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef ESPRITE_HPP
#define ESPRITE_HPP

#include <raylib.h>
#include <string>

class ESprite {
public:
    explicit ESprite(const std::string &path, Color color = WHITE);
    ~ESprite();
    void setColor(const Color &color);
    [[nodiscard]] const Color &getColor() const;
    [[nodiscard]] const Rectangle &getRect() const;
    void draw(Vector3 pos);
    [[nodiscard]] const Texture2D &getTex() const;
protected:
    Texture2D _tex;
    Rectangle _spriteRect;
    Color _tintColor;
};

#endif //ESPRITE_HPP