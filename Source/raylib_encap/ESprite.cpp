/*
** EPITECH PROJECT, 2024
** ESprite.cpp
** File description:
** Created by Leo Fabre
*/
#include <iostream>
#include "raylib_encap/ESprite.hpp"

ESprite::ESprite(const std::string &path, Color color)
    : Texture2D(LoadTexture(path.c_str())),
      _tintColor(color), path(path)
{
}

void ESprite::draw(Vector3 pos)
{
    DrawTexture(*this, (int) pos.x, (int) pos.y, _tintColor);
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
    std::cerr << "UNLOADING TEXTURE (" << path << ")" << std::endl;
    UnloadTexture(*this);
}

ESprite::ESprite(Texture2D texture)
    : Texture2D(texture),
      _tintColor(WHITE)
{
}
