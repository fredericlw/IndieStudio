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

void Manager::loadScene(const Scene &sceneToLoad)
{
    std::cout << "!!! LoadScene !!!" << std::endl;
    //set inactive all entities except dontDestroyOnLoad ones
    for (auto &item : entities)
        if (!item->GetDontDestroyOnLoad())
            item->destroy();
    std::cout << "Refreshing..." << std::endl;
    refresh();
    std::cout << "Loading Entities from scene..." << std::endl;
    //Load entities from scene
    for (auto &item : sceneToLoad.entities) {
        std::cout << "loading " << item->getName() << std::endl;
        entities.emplace_back(std::move(item.get()));
        std::cout << "loaded entity " << item.get()->getName() << std::endl;
    }
}
