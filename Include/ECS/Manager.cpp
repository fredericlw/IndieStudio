/*
** EPITECH PROJECT, 2024
** Manager.cpp
** File description:
** Created by Leo Fabre
*/
#include <raylib.h>

#include <utility>
#include "Manager.hpp"

void Manager::update()
{
    for (auto &e : entities) e->update();
}

void Manager::draw()
{
    BeginDrawing();
    for (auto &e : entities) e->draw();
    EndDrawing();
}

void Manager::refresh()
{
    entities.erase(std::remove_if(std::begin(entities), std::end(entities),
        [](const std::unique_ptr<Entity> &mEntity) {
            return !mEntity->isActive() && !mEntity->GetDontDestroyOnLoad();
        }),
        std::end(entities));
}

Entity &Manager::addEntity(std::string name)
{
    auto *e = new Entity(std::move(name));
    std::unique_ptr<Entity> ptr{e};
    entities.emplace_back(std::move(ptr));
    return *e;
}

void Manager::loadScene(Scene sceneToLoad)
{
    //set inactive all entities except dontDestroyOnLoad ones
    for (auto &item : entities)
        if (!item->GetDontDestroyOnLoad())
            item->destroy();
    refresh();
    //Load entities from scenes
    for (auto &item : sceneToLoad.entities) {
        std::unique_ptr<Entity> uptr{&item};
        entities.emplace_back(std::move(uptr));
    }
}
