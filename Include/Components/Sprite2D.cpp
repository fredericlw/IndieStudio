/*
** EPITECH PROJECT, 2024
** Sprite2D.cpp
** File description:
** Created by Leo Fabre
*/
#include "Sprite2D.hpp"
#include "ECS/Entity.hpp"

Sprite2D::Sprite2D(const std::string &path)
{
    tex = LoadTexture(path.c_str());
}

void Sprite2D::init()
{
    Component::init();
    transform = &entity->getComponent<TransformComp>();
    if (transform == nullptr) {
        transform = &entity->addComponent<TransformComp>();
    }
    Rect.x = 0;
    Rect.y = 0;
    Rect.height = tex.height;
    Rect.width = tex.width;
    
}

void Sprite2D::update()
{
    Component::update();
}

void Sprite2D::draw()
{
    Component::draw();
    DrawTexture(tex,
        (int)transform->position.x, (int)transform->position.y, RAYWHITE);
}

const Rectangle &Sprite2D::getRect() const
{
    return Rect;
}

const Texture2D &Sprite2D::getTex() const
{
    return tex;
}
