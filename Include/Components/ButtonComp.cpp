/*
** EPITECH PROJECT, 2024
** ButtonComp.cpp
** File description:
** Created by Leo Fabre
*/
#include <raylib_encap/Vector2D.hpp>
#include "ButtonComp.hpp"
#include "ECS/Entity.hpp"
#include "Components.h"

ButtonComp::ButtonComp(const std::string &text, Vector2D size, Vector2D pos)
    : _text(text),
      size(size),
      pos(pos),
      _rect(size, pos)
{
}

void ButtonComp::init()
{
    Component::init();
    transform = &entity->getComponent<TransformComp>();
}

void ButtonComp::update()
{
    if (CheckCollisionPointRec(GetMousePosition(), _rect)) {
        hovering = true;
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            for (const auto &func : EventFuncs)
                func();
    } else {hovering = false;}

    //pos = transform->position;
    _rect.x = pos.x;
    _rect.y = pos.y;
    _rect.width = size.x;
    _rect.height = size.y;
}

void ButtonComp::draw()
{
    Component::draw();

    DrawRectangleRec(_rect, (hovering) ? GREEN : LIGHTGRAY);
    DrawRectangleLines((int) _rect.x, (int) _rect.y, (int) _rect.width,
        (int) _rect.height,
        (hovering) ? GREEN : GRAY);
    DrawText(_text.c_str(),
        (int) (_rect.x + _rect.width / 2 - MeasureText(_text.c_str(), 40) / 2),
        (int) _rect.y + 11, 40, hovering ? DARKBLUE : DARKGRAY);
}

void ButtonComp::AddEventFunc(const std::function<void()> &function)
{
    EventFuncs.emplace_back(function);
}
