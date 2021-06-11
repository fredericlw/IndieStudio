/*
** EPITECH PROJECT, 2024
** Manager.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <raylib_encap/ECamera.hpp>
#include <Ecs.hpp>

enum GroupLabel{
    Background,
    Floor,
    Walls,
    Obstacles,
    Bombs,
    Players,
    Particles,
    GUI,
    GUI_TOP,
    PowerUps
};
class Entity;

class Manager {
public:
    enum SceneType{
        MainMenu,
        Game,
        Lobby,
        Settings,
        HowToPlay,
        GameOverScene,
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
public:
    bool isAlive() const;
private:
    bool alive = true;
    std::vector<std::shared_ptr<Entity>> entities;
    std::array<std::vector<Entity *>, maxGroups> groupedEntities;
public:
    std::shared_ptr<Entity> getEntByName(const std::string &name);
    void setAlive(bool alive);
private:
    SceneType nextSceneToLoad;
public:
    SceneType getNextSceneToLoad() const;
    void setNextSceneToLoad(SceneType next_scene_to_load);

    void loadGameScene();
    void loadMenuScene();
    void addBackToGameBtn();
    void addBackToGameOptionBtn();
    void addBackToHowToPlayButton();
    void AddMenuLogo();
    void AddPlayButton();
    void GenerateMap();
    void loadLobbyScene();
    void AddMenuButton();
    void AddGameButton();
    void AddLobbyName();
    void AddOptionName();
    void AddHowToPlayName();
    void AddHowToPlayRules();
    void loadHowToPlayScene();
    void loadOptionScene();
    void AddSettingsButton();
    void AddHowToPlayButton();
    void loadGameOverScene();
};

#endif //MANAGER_HPP