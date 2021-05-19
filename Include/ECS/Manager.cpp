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
    ClearBackground(DARKPURPLE);
    BeginDrawing();
    for (auto &e : entities) e->draw();
    EndDrawing();
}

void Manager::refresh()
{
    entities.erase(std::remove_if(std::begin(entities), std::end(entities),
        [](const std::shared_ptr<Entity> &mEntity) {
            return !mEntity->isActive() && !mEntity->GetDontDestroyOnLoad();
        }),
        std::end(entities));
}

Entity &Manager::addEntity(std::string name)
{
    auto *e = new Entity(std::move(name));
    std::shared_ptr<Entity> ptr{e};
    entities.emplace_back(std::move(ptr));
    return *e;
}

void Manager::loadScene(const Scene &sceneToLoad)
{
    std::cout << "!!! LoadScene !!!" << std::endl;
    //set inactive all entities except dontDestroyOnLoad ones
    for (auto &item : entities)
        if (!item->GetDontDestroyOnLoad())
            item->destroy();
    refresh();
    //Load entities from scene
    for (auto &item : sceneToLoad.entities) {
        entities.emplace_back(std::move(item.get()));
    }
}
