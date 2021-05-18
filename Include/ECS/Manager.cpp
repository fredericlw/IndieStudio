/*
** EPITECH PROJECT, 2024
** Manager.cpp
** File description:
** Created by Leo Fabre
*/
#include "Manager.hpp"

void Manager::update()
{
    for (auto &e : entities) e->update();
}

void Manager::draw()
{
    for (auto &e : entities) e->draw();
}

void Manager::refresh()
{
    entities.erase(std::remove_if(std::begin(entities), std::end(entities),
        [](const std::unique_ptr<Entity> &mEntity) {
            return !mEntity->isActive();
        }),
        std::end(entities));
}

Entity &Manager::addEntity()
{
    Entity *e = new Entity;
    std::unique_ptr<Entity> ptr{e};
    entities.emplace_back(std::move(ptr));
    return *e;
}
