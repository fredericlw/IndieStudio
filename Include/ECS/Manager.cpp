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
    for (auto &e : entities) {
        e->draw();
    }
    EndDrawing();
}

void Manager::refresh()
{
    for (auto i(0u); i < maxGroups; i++) {
        auto &v(groupedEntities[i]);
        v.erase(
            std::remove_if(std::begin(v), std::end(v), [i](Entity *entity) {
                return ((!entity->isActive() && !entity->GetDontDestroyOnLoad())
                    || !entity->hasGroup(i));
            }), std::end(v)
        );
    }
    entities.erase(std::remove_if(std::begin(entities), std::end(entities),
        [](const std::shared_ptr<Entity> &entity) {
            return !entity->isActive() && !entity->GetDontDestroyOnLoad();
        }),
        std::end(entities));
}

Entity &Manager::addEntity(std::string name)
{
    auto *e = new Entity(std::move(name), *this);
    std::shared_ptr<Entity> ptr{e};
    entities.emplace_back(std::move(ptr));
    return *e;
}

void Manager::destroyOnLoad()
{
    std::cout << "!!! LoadScene !!!" << std::endl;
    //set inactive all entities except dontDestroyOnLoad ones
    for (auto &item : entities) {
        if (!item->GetDontDestroyOnLoad())
            item->destroy();
    }
    refresh();
}

Manager::Manager()
{
    MainCam.position = Vector3{0.0f, 10.0f, 10.0f};
    MainCam.target = Vector3{0.0f, 0.0f, 0.0f};
    MainCam.up = Vector3{0.0f, 1.0f, 0.0f};
    MainCam.fovy = 45.0f;
    MainCam.projection = CAMERA_PERSPECTIVE;
}

void Manager::loadScene(Manager::SceneType scene)
{
    destroyOnLoad();
    switch (scene) {
    case MainMenu:
        loadMenuScene();
        break;
    case Game:
        loadGameScene();
        break;
    }
}

void Manager::Quit()
{
    alive = false;
}

bool Manager::isAlive() const
{
    return alive;
}

void Manager::loadGameScene()
{
    AddCubeZER();
}

void Manager::addEntityToGroup(Entity *entity, Group group)
{
    groupedEntities[group].emplace_back(entity);
}

std::vector<Entity *> &Manager::getEntitiesInGroup(Group group)
{
    return groupedEntities[group];
}
