/*
** EPITECH PROJECT, 2024
** EText.cpp
** File description:
** Created by Leo Fabre
*/
#include <raylib.h>

#include <utility>
#include "EText.hpp"

EText::~EText()
{
}

void EText::draw(int posX, int posY, int size)
{
    DrawText(_text.c_str(), posX, posY, size, GetRaylibColor(_color));
}

void EText::drawInRectCenter(ERect _rect, int size)
{
    DrawText(_text.c_str(),
        (int) (_rect.x + _rect.width / 2 -
            MeasureText(_text.c_str(), size) / 2),
        (int) _rect.y + 10, size, GetRaylibColor(_color));
}

EText::EText(std::string text)
    : _text(std::move(text)),
      _color(RayWhite)
{
}

void EText::setColor(Colors color)
{
    _color = color;
}

