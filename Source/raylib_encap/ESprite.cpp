/*
** EPITECH PROJECT, 2024
** ESprite.cpp
** File description:
** Created by Leo Fabre
*/
#include <iostream>
#include <raylib_encap/ERect.hpp>
#include "raylib_encap/ESprite.hpp"

ESprite::ESprite(const std::string &path, Colors color)
    : Texture2D(LoadTexture(path.c_str())),
      _tintColor(color), path(path)
{
}

ESprite::ESprite()
{

}

void ESprite::draw(Vector3 pos)
{
    if (!path.empty())
        DrawTexture(*this, (int) pos.x, (int) pos.y, GetRaylibColor(_tintColor));
}

void ESprite::drawInRect(Vector2D pos, ERect frameRect)
{
    if (!path.empty())
        DrawTextureRec(*this, frameRect, pos, GetRaylibColor(_tintColor));
}

const Rectangle &ESprite::getRect() const
{
    return _spriteRect;
}

const Colors &ESprite::getColor() const
{
    return _tintColor;
}

void ESprite::setColor(const Colors &color)
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
      _tintColor(White)
{
}

void ESprite::setTex(const std::string &path, Colors color)
{
    *this = LoadTexture(path.c_str());
    _tintColor = color;
}

void ESprite::drawBillboardRect(Camera camera, Rectangle rect,
    Vector3 position, Vector2 size, Colors tint)
{
    DrawBillboardRec(camera, *this, rect, position, size, GetRaylibColor(tint));
}
