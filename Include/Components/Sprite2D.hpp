/*
** EPITECH PROJECT, 2024
** Sprite2D.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef SPRITE2D_HPP
#define SPRITE2D_HPP

#include <ECS/Component.hpp>
#include <raylib.h>
#include "PositionComponent.hpp"

class Sprite2D : public Component {
public:
    Sprite2D(const std::string &path);
    void init() override;
    void update() override;
    void draw() override;
private:
    PositionComponent *pos;
    Texture2D tex;
public:
    const Texture2D &getTex() const;
private:
    Rectangle srcRect;
    Rectangle destRect;
public:
    const Rectangle &getRect() const;
};

#endif //SPRITE2D_HPP