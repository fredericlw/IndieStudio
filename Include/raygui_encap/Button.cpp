/*
** EPITECH PROJECT, 2024
** Button.cpp
** File description:
** Created by Leo Fabre
*/
#include <raylib_encap/ERect.hpp>
#include <utility>
#include "Button.hpp"

Button::Button(const ERect& rect, std::string text)
    : _rect(rect),
      _text(std::move(text))
{
}

Button::~Button()
{
}

bool Button::draw()
{
    //returns true when clicked
    GuiButton(_rect, _text.c_str());
}
