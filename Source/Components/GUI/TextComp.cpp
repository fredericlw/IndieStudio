/*
** EPITECH PROJECT, 2024
** TextComp.cpp
** File description:
** Created by Frederic LAWECKI--WALKOWIAK
*/

#include "Components/GUI/TextComp.hpp"
#include "Entity.hpp"

void TextComp::init()
{
    Component::init();
    transform = &entity->getComponent<TransformComp>();
    if (!transform)
        transform = &entity->addComponent<TransformComp>();
}

void TextComp::update()
{
    Component::update();
}

void TextComp::draw()
{
    Component::draw();
    if (!visible) return;
    EText::drawCentered(transform->position.x, transform->position.y, _size,
        TextColor);
}

void TextComp::setVisible(bool visible)
{
    TextComp::visible = visible;
}

TextComp::TextComp(
    const std::string &text, Colors color, int size, bool visible
)
    : EText(text),
      TextColor(color),
      _size(size),
      visible(visible)
{
}
