/*
** EPITECH PROJECT, 2024
** ESprite.cpp
** File description:
** Created by Leo Fabre
*/
#include "ESprite.hpp"

ESprite::ESprite(const std::string &path, Color color) : _tex(LoadTexture(path.c_str())),
                                                         _tintColor(color)
{
}

void ESprite::draw(Vector3 pos)
{
    DrawTexture(_tex, (int) pos.x, (int) pos.y, _tintColor);
}

const Texture2D &ESprite::getTex() const
{
    return _tex;
}

const Rectangle &ESprite::getRect() const
{
    return _spriteRect;
}

const Color &ESprite::getColor() const
{
    return _tintColor;
}

void ESprite::setColor(const Color &color)
{
    _tintColor = color;
}

ESprite::~ESprite()
{
}
