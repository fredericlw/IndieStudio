/*
** EPITECH PROJECT, 2024
** Sprite2D.cpp
** File description:
** Created by Leo Fabre
*/
#include "Components/GUI/Sprite2D.hpp"
#include "ECS/Entity.hpp"

Sprite2D::Sprite2D(const std::string &path) : ESprite(path)
{
}

void Sprite2D::init()
{
    Component::init();
    transform = &entity->getComponent<TransformComp>();
    if (transform == nullptr) {
        transform = &entity->addComponent<TransformComp>();
    }
    _spriteRect.x = 0;
    _spriteRect.y = 0;
    _spriteRect.height = (float) height;
    _spriteRect.width = (float) width;
}

void Sprite2D::update()
{
    Component::update();
}

void Sprite2D::draw()
{
    Component::draw();
    ESprite::draw(transform->position);
}

Sprite2D::Sprite2D(ESprite &sprite) : ESprite(sprite)
{

}
