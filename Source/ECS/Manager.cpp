/*
** EPITECH PROJECT, 2024
** Manager.cpp
** File description:
** Created by Leo Fabre
*/
#include <raylib.h>

#include <utility>
#include <raylib_encap/Math/Vector3D.hpp>
#include "ECS/Manager.hpp"
#include "Components.h"

void Manager::update() {
    for (auto &e : entities) e->update();
}

void Manager::draw() {
    ClearBackground(DARKPURPLE);
    BeginDrawing();
    for (auto &e : entities) {
        e->draw();
    }
    EndDrawing();
}

void Manager::refresh() {
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

Entity &Manager::addEntity(std::string name) {
    auto *e = new Entity(std::move(name), *this);
    std::shared_ptr<Entity> ptr{e};
    entities.emplace_back(std::move(ptr));
    return *e;
}

void Manager::destroyOnLoad() {
    std::cout << "!!! LoadScene !!!" << std::endl;
    //set inactive all entities except dontDestroyOnLoad ones
    for (auto &item : entities) {
        if (!item->GetDontDestroyOnLoad())
            item->destroy();
    }
    refresh();
}

Manager::Manager() {
    MainCam.position = Vector3{0.0f, 10.0f, 10.0f};
    MainCam.target = Vector3{0.0f, 0.0f, 0.0f};
    MainCam.up = Vector3{0.0f, 1.0f, 0.0f};
    MainCam.fovy = 45.0f;
    MainCam.projection = CAMERA_PERSPECTIVE;
    nextSceneToLoad = None;
}

void Manager::loadScene(Manager::SceneType scene) {
    destroyOnLoad();
    switch (scene) {
        case MainMenu:
            loadMenuScene();
            break;
        case Game:
            loadGameScene();
            break;
        case Lobby:
            loadLobbyScene();
            break;
    }
}

void Manager::Quit() {
    alive = false;
}

bool Manager::isAlive() const {
    return alive;
}


void Manager::addEntityToGroup(Entity *entity, Group group) {
    groupedEntities[group].emplace_back(entity);
}

std::vector<Entity *> &Manager::getEntitiesInGroup(Group group) {
    return groupedEntities[group];
}


Manager::SceneType Manager::getNextSceneToLoad() const {
    return nextSceneToLoad;
}

void Manager::setNextSceneToLoad(Manager::SceneType next_scene_to_load) {
    nextSceneToLoad = next_scene_to_load;
}

void Manager::setAlive(bool alive) {
    Manager::alive = alive;
}

std::shared_ptr<Entity> Manager::getEntByName(const std::string &name)
{
    for (auto a : entities)
    {
        if (a->getName() == name)
            return a;
    }
    return nullptr;
}


