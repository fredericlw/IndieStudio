/*
** EPITECH PROJECT, 2024
** Entity.cpp
** File description:
** Created by Leo Fabre
*/
#include "Entity.hpp"

void Entity::update()
{
    for (auto &c : components) c->update();
}

void Entity::destroy()
{
    active = false;
}

template<typename T> bool Entity::hasComponent() const
{
    return componentBitSet[getComponentTypeID<T>()];
}

void Entity::draw()
{
    for (auto &c : components) c->draw();
}
