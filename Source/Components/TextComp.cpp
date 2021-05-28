/*
** EPITECH PROJECT, 2024
** TextComp.cpp
** File description:
** Created by Frederic LAWECKI--WALKOWIAK
*/

#include "Components/GUI/TextComp.hpp"
#include "Entity.hpp"

void TextComp::init() {
    Component::init();
    transform = &entity->getComponent<TransformComp>();
    if (!transform)
        transform = &entity->addComponent<TransformComp>();
}

void TextComp::update() {
    Component::update();
}

void TextComp::draw() {
    Component::draw();
    EText::drawCentered(transform->position.x, transform->position.y, 40, TextColor);
}

TextComp::TextComp(const std::string &text, Colors color) : EText(text), TextColor(color){

}
