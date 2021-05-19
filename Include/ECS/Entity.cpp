/*
** EPITECH PROJECT, 2024
** Entity.cpp
** File description:
** Created by Leo Fabre
*/
#include "Entity.hpp"
#include "Manager.hpp"
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

Entity::Entity(std::string name, std::shared_ptr<Manager> mgr)
    : _name(std::move(name)), _mgr(std::move(mgr))
{
    std::cout << "maincam : " << _mgr->MainCam.position.x << " " << _mgr->MainCam.position.y
        << " " << _mgr->MainCam.position.z << std::endl;
}

const std::string &Entity::getName() const
{
    return _name;
}
