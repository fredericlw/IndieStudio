/*
** EPITECH PROJECT, 2024
** Scene.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include <ECS/Ecs.hpp>
#include "ECS/Entity.hpp"

//Abstract class
class Scene {
public:
    virtual ~Scene(){}
    std::vector<std::shared_ptr<Entity>> entities;
};

#endif //SCENE_HPP