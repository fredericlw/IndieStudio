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
    explicit Manager();
    void update();
    void draw();
    void refresh();
    Entity &addEntity(std::string name);
    void destroyOnLoad();
private:
    std::vector<std::shared_ptr<Entity>> entities;
    Camera3D MainCam;
};

#endif //MANAGER_HPP