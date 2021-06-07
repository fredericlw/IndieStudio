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
#include <Colors.h>
#include <raylib_encap/Math/Vector3D.hpp>
#include <raylib_encap/ERect.hpp>

class ESprite : public Texture2D {
public:
    explicit ESprite(const std::string &path = "", Colors color = White);
    ESprite(Texture2D texture);
    ESprite();
    ~ESprite();
    void setColor(const Colors &color);
    [[nodiscard]] const Colors &getColor() const;
    [[nodiscard]] const Rectangle &getRect() const;
    void draw(Vector3 pos);
    void drawInRect(Vector2D pos, ERect frameRect);
    [[nodiscard]] const Texture2D &getTex() const;
    void drawBillboardRect(
        Camera camera, Rectangle rect, Vector3 position, Vector2 size,
        Colors tint = White
    );
    void setTex(const std::string &path, Colors color = White);
protected:
    Rectangle _spriteRect;
    Colors _tintColor;
    std::string path;
};
    
#endif //ESPRITE_HPP