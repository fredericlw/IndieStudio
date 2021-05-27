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

class ESprite : public Texture2D {
public:
    explicit ESprite(const std::string &path = "", Color color = WHITE);
    ESprite(Texture2D texture);
    ~ESprite();
    void setColor(const Color &color);
    [[nodiscard]] const Color &getColor() const;
    [[nodiscard]] const Rectangle &getRect() const;
    void draw(Vector3 pos);
    [[nodiscard]] const Texture2D &getTex() const;
protected:
    Rectangle _spriteRect;
    Color _tintColor;
    std::string path;
};

#endif //ESPRITE_HPP