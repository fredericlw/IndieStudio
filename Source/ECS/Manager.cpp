/*
** EPITECH PROJECT, 2024
** Manager.cpp
** File description:
** Created by Leo Fabre
*/
#include "Manager.hpp"
#include "boost/filesystem.hpp"
#include <raylib_encap/EAudio.hpp>
#include "Bomberman.hpp"
#include <Components/3D/BasicCubeComp.hpp>
#include <Components/GUI/Sprite2D.hpp>
#include <Components/3D/TransformComp.hpp>
#include "raylib_encap/Window.hpp"
#include <memory>
#include <iostream>
#include <raylib.h>

#include <utility>
#include <raylib_encap/Math/Vector3D.hpp>
#include "ECS/Manager.hpp"
#include "Components.h"

void Manager::SceneLoop()
{
    std::cout << "SCENE LOOP BEGIN" << std::endl;
    setAlive(true);
    while (isAlive() && !mainWindow->ShouldClose()) {
        update();
        refresh();
        draw();
    }
    std::cerr << "SCENE LOOP END" << std::endl;
    if (getNextSceneToLoad() != None) {
        loadScene(getNextSceneToLoad());
        SceneLoop();
    }
}

void Manager::update()
{
    for (auto &e : entities)
        e->update();
    MainCam.Update();
}

void Manager::draw()
{
    auto &bg(getEntitiesInGroup(Background));
    auto &floorEnts(getEntitiesInGroup(Floor));
    auto &walls(getEntitiesInGroup(Walls));
    auto &obstacles(getEntitiesInGroup(Obstacles));
    auto &bombs(getEntitiesInGroup(Bombs));
    auto &powerups(getEntitiesInGroup(PowerUps));
    auto &players(getEntitiesInGroup(Players));
    auto &particles(getEntitiesInGroup(Particles));
    auto &guiEnts(getEntitiesInGroup(GUI));
    auto &guiEnts2(getEntitiesInGroup(GUI_TOP));

    ClearBackground(DARKPURPLE);
    BeginDrawing();
    MainCam.End3D();
    for (const auto &ent : bg)
        ent->draw();
    MainCam.Begin3D();
    for (auto &ent : floorEnts)
        ent->draw();
    for (auto &ent : walls)
        ent->draw();
    for (auto &ent : obstacles)
        ent->draw();
    for (auto &ent : bombs)
        ent->draw();
    for (auto &ent : powerups)
        ent->draw();
    for (auto &ent : players)
        ent->draw();
    for (auto &ent : particles)
        ent->draw();
    MainCam.End3D();
    for (auto &ent : guiEnts)
        ent->draw();
    for (auto &ent : guiEnts2)
        ent->draw();
    EndDrawing();
}

void Manager::refresh()
{
    for (auto i(0u); i < maxGroups; i++) {
        auto &v(groupedEntities[i]);
        v.erase(std::remove_if(std::begin(v), std::end(v), [i](Entity *entity) {
            return ((!entity->isActive() && !entity->GetDontDestroyOnLoad()) ||
                !entity->hasGroup(i));
        }), std::end(v));
    }
    entities.erase(std::remove_if(std::begin(entities), std::end(entities),
        [](const std::shared_ptr<Entity> &entity) {
            return !entity->isActive() && !entity->GetDontDestroyOnLoad();
        }), std::end(entities));
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

Manager::Manager(std::shared_ptr<Window> mainWindow) : mainWindow(mainWindow)
{
    MainCam.position = Vector3D{0.0f, 10.0f, 14.0f};
    MainCam.target = Vector3D{0.0f, 0.0f, 8.0f};
    MainCam.up = Vector3D{0.0f, 1.0f, 0.0f};
    MainCam.fovy = 35.0f;
    MainCam.projection = CAMERA_PERSPECTIVE;
    nextSceneToLoad = None;
}

void Manager::loadScene(Manager::SceneType scene)
{
    destroyOnLoad();
    switch (scene) {
    case MainMenu:
        loadMenuScene();
        break;
    case Settings:
        loadOptionScene();
        break;
    case Game:
        loadGameScene();
        break;
    case Lobby:
        loadLobbyScene();
        break;
    case HowToPlay:
        loadHowToPlayScene();
        break;
    case GameOverScene:
        loadGameOverScene();
        break;
    case Controls:
        loadControlsScene();
        break;
    case AboutPowerUps:
        loadAboutPowerUpsScene();
        break;
    case None:
        break;
    }
    setNextSceneToLoad(Manager::None);
}

void Manager::Quit()
{
    curSceneAlive = false;
}

bool Manager::isAlive() const
{
    return curSceneAlive;
}

void Manager::addEntityToGroup(Entity *entity, Group group)
{
    groupedEntities[group].emplace_back(entity);
}

std::vector<Entity *> &Manager::getEntitiesInGroup(Group group)
{
    return groupedEntities[group];
}

Manager::SceneType Manager::getNextSceneToLoad() const
{
    return nextSceneToLoad;
}

void Manager::setNextSceneToLoad(Manager::SceneType next_scene_to_load)
{
    nextSceneToLoad = next_scene_to_load;
}

void Manager::setAlive(bool alive)
{
    Manager::curSceneAlive = alive;
}

std::shared_ptr<Entity> Manager::getEntByName(const std::string &name)
{
    for (auto a : entities) {
        if (a->getName() == name)
            return a;
    }
    return nullptr;
}
