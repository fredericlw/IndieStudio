/*
** EPITECH PROJECT, 2024
** ButtonComp.cpp
** File description:
** Created by Leo Fabre
*/
#include <raylib/Vector2D.hpp>
#include "ButtonComp.hpp"
#include "ECS/Entity.hpp"
#include "Components.h"

ButtonComp::ButtonComp(const std::string &text, Vector2D size, Vector2D pos)
    : _text(text),
      size(size),
      pos(pos)
{
}

void ButtonComp::init()
{
    Component::init();
    transform = &entity->getComponent<TransformComp>();
}

void ButtonComp::update()
{
    if (CheckCollisionPointRec(GetMousePosition(), rect)) {
        hovering = true;
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            for (const auto &func : EventFuncs)
                func();
    } else {hovering = false;}

    //pos = transform->position;
    rect.x = pos.x;
    rect.y = pos.y;
    rect.width = size.x;
    rect.height = size.y;
}

void ButtonComp::draw()
{
    Component::draw();

    DrawRectangleRec(rect, (hovering) ? GREEN : LIGHTGRAY);
    DrawRectangleLines((int) rect.x, (int) rect.y, (int) rect.width,
        (int) rect.height,
        (hovering) ? GREEN : GRAY);
    DrawText(_text.c_str(),
        (int) (rect.x + rect.width / 2 - MeasureText(_text.c_str(), 40) / 2),
        (int) rect.y + 11, 40, hovering ? DARKBLUE : DARKGRAY);
}

void ButtonComp::AddEventFunc(const std::function<void()> &function)
{
    EventFuncs.emplace_back(function);
}
