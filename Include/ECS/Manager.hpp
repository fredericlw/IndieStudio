/*
** EPITECH PROJECT, 2024
** Manager.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <Scene.hpp>
#include <raylib_encap/ECamera.hpp>
#include "Entity.hpp"

enum GroupLabel{
    Walls,
    Obstacles,
    Bombs,
    Players,
    GUI
};

class Manager {
public:
    enum SceneType{
        MainMenu,
        Game,
        Lobby,
        None
    };
    explicit Manager();
    void update();
    void draw();
    void refresh();
    Entity &addEntity(std::string name);
    void addEntityToGroup(Entity *entity, Group group);
    std::vector<Entity *> &getEntitiesInGroup(Group group);
    void destroyOnLoad();
    void loadScene(SceneType scene);
    void Quit();
    ECamera MainCam;
private:
public:
    bool isAlive() const;
private:
    bool alive = true;
    std::vector<std::shared_ptr<Entity>> entities;
    std::array<std::vector<Entity *>, maxGroups> groupedEntities;
    void loadGameScene();
    void loadMenuScene();
    void AddQuitButton();
    void AddMenuLogo();
    void AddPlayButton();
    void AddCubeZER();
    void GenerateMap();
public:
    std::shared_ptr<Entity> getEntByName(const std::string &name);
    void setAlive(bool alive);
private:
    SceneType nextSceneToLoad;
public:
    SceneType getNextSceneToLoad() const;
    void setNextSceneToLoad(SceneType next_scene_to_load);

    void loadLobbyScene();

    void AddMenuButton();

    void AddGameButton();

    void AddLobbyName();

    void AddListSelector();
};

#endif //MANAGER_HPP