/*
** EPITECH PROJECT, 2024
** ButtonComp.cpp
** File description:
** Created by Leo Fabre
*/
#include <raylib_encap/Vector2D.hpp>
#include <raylib_encap/RectCollider.hpp>
#include <raylib_encap/EMouseInputModule.hpp>
#include <Colors.h>
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
    if (!transform) {
        transform = &entity->addComponent<TransformComp>();
    }
}

void ButtonComp::update()
{
    if (RectCollider::CheckMouseInRect(_rect)) {
        hovering = true;
        if (EMouseInputModule::GetButtonReleased(LeftClick))
            for (const auto &func : EventFuncs)
                func();
    } else {
        hovering = false;
    }
    _rect.x = pos.x;
    _rect.y = pos.y;
    _rect.width = size.x;
    _rect.height = size.y;
}

void ButtonComp::draw()
{
    Component::draw();
    _rect.draw(true, true, (hovering) ? Green : LightGray,
        (hovering) ? Green : Gray);

    _text.drawInRectCenter(_rect, 40);
}

void ButtonComp::AddEventFunc(const std::function<void()> &function)
{
    EventFuncs.emplace_back(function);
}
