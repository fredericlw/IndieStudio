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
    void update();
    void draw();
    void refresh();
    Entity &addEntity(std::string name);
    void loadScene(const Scene& sceneToLoad);
private:
    std::vector<std::unique_ptr<Entity>> entities;
};

#endif //MANAGER_HPP