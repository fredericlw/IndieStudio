/*
** EPITECH PROJECT, 2024
** Manager.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef MANAGER_HPP
#define MANAGER_HPP
#include "Entity.hpp"

class Manager {
public:
    void update();
    void draw();
    void refresh();
    Entity& addEntity();
private:
    std::vector<std::unique_ptr<Entity>> entities;
};

#endif //MANAGER_HPP