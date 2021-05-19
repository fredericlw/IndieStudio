/*
** EPITECH PROJECT, 2024
** Manager.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <Scene.hpp>
#include "Entity.hpp"

class Manager {
public:
    enum SceneType{
        MainMenu,
        Game
    };

    explicit Manager();
    void update();
    void draw();
    void refresh();
    Entity &addEntity(std::string name);
    void destroyOnLoad();
    void loadScene(SceneType scene);
    void LoadMenuScene();
    void loadGamescene();
    void AddMenuLogo();
    void AddPlayButton();
    void AddCubeZER();
    void Quit();
    Camera3D MainCam;
private:
public:
    bool isAlive() const;
private:
    bool alive = true;
    std::vector<std::shared_ptr<Entity>> entities;
    void loadGameScene();
    void loadMenuScene();
    void AddQuitButton();
};

#endif //MANAGER_HPP