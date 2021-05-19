/*
** EPITECH PROJECT, 2024
** Entity.cpp
** File description:
** Created by Leo Fabre
*/
#include "Entity.hpp"

#include <utility>

void Entity::update()
{
    for (auto &c : components) c->update();
}

void Entity::destroy()
{
    _active = false;
}

template<typename T> bool Entity::hasComponent() const
{
    return componentBitSet[getComponentTypeID<T>()];
}

void Entity::draw()
{
    for (auto &c : components) c->draw();
}

Entity::Entity(std::string name, Camera3D MainCam)
    : _name(std::move(name)),
      MainCam(MainCam)
{
    std::cout << "maincam : " << MainCam.position.x << " " << MainCam.position.y
        << " " << MainCam.position.z << std::endl;
}

const std::string &Entity::getName() const
{
    return _name;
}
