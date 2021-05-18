/*
** EPITECH PROJECT, 2024
** Scene.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include "Entity.hpp"

class Scene {
public:
    std::vector<Entity> entities;
};

#endif //SCENE_HPP