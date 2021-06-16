/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include "Components/GUI/ResizableTextComp.hpp"
#include "Entity.hpp"

void ResizableTextComp::init() {
    Component::init();
    transform = &entity->getComponent<TransformComp>();
    if (!transform)
        transform = &entity->addComponent<TransformComp>();
}

void ResizableTextComp::update() {
    Component::update();
}

void ResizableTextComp::draw() {
    Component::draw();
    EText::drawCentered(transform->position.x, transform->position.y, size, TextColor);
}

ResizableTextComp::ResizableTextComp(const std::string &text, Colors color, int size) : EText(text), TextColor(color), size(size)
{
}
