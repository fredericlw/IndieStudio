/*
** EPITECH PROJECT, 2024
** Sprite2D.cpp
** File description:
** Created by Leo Fabre
*/
#include "Sprite2D.hpp"
#include "ECS/Entity.hpp"

Sprite2D::Sprite2D(const std::string &path)
{
    tex = LoadTexture(path.c_str());
}

void Sprite2D::init()
{
    Component::init();
    pos = &entity->getComponent<PositionComponent>();
    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.height = 32;
    srcRect.width = 32;
    destRect.width = 64;
    destRect.height = 64;
}

void Sprite2D::update()
{
    Component::update();
    destRect.x = pos->x();
    destRect.y = pos->y();
}

void Sprite2D::draw()
{
    Component::draw();
    DrawTexture(tex, pos->x(), pos->y(), RAYWHITE);
}

const Rectangle &Sprite2D::getRect() const
{
    return destRect;
}

const Texture2D &Sprite2D::getTex() const
{
    return tex;
}
