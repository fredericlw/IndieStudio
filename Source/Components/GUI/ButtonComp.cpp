/*
** EPITECH PROJECT, 2024
** ButtonComp.cpp
** File description:
** Created by Leo Fabre
*/
#include <raylib_encap/Math/Vector2D.hpp>
#include <raylib_encap/Math/RectCollider.hpp>
#include <raylib_encap/Input/EMouseInputModule.hpp>
#include <Colors.h>
#include "Components/GUI/ButtonComp.hpp"
#include "ECS/Entity.hpp"
#include "Components/Components.h"

ButtonComp::ButtonComp(
    const std::string &text, Vector2D size, bool visible
)
    : _text(text),
      size(size),
      _rect(size, Vector2D::Zero()),
      Visible(visible)
{
}

void ButtonComp::init()
{
    Component::init();
    transform = &entity->getComponent<TransformComp>();
    if (!transform)
        transform = &entity->addComponent<TransformComp>();
    _rect.x = transform->position.x;
    _rect.y = transform->position.y;
    _rect.width = size.x;
    _rect.height = size.y;
}

void ButtonComp::update()
{
    if (!Visible)
        return;
    if (RectCollider::CheckMouseInRect(_rect)) {
        hovering = true;
        if (EMouseInputModule::GetButtonReleased(LeftClick)) {
            entity->assets()->ButtonClick.playSound(entity->assets()->Volume);
            for (const auto &func : EventFuncs)
                func();
        }
    } else {
        hovering = false;
    }
}

void ButtonComp::draw()
{
    Component::draw();
    if (!Visible)
        return;
    if (!hovering) {
        _rect.draw(true, true, LightGray, Gray);
    } else {
        _rect.draw(true, false, (hovering) ? DarkGray : LightGray,
            (hovering) ? White : Gray);
    }

    _text.drawInRectCenter(_rect, 40, (hovering) ? White : DarkGray);
}

void ButtonComp::AddEventFunc(const std::function<void()> &function)
{
    EventFuncs.emplace_back(function);
}

bool ButtonComp::isVisible() const
{
    return Visible;
}

void ButtonComp::setVisible(bool visible)
{
    Visible = visible;
}
