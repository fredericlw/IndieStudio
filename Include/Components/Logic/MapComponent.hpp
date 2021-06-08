/*
** EPITECH PROJECT, 2024
** MapComponent.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef MAPCOMPONENT_HPP
#define MAPCOMPONENT_HPP

#include "ECS/Component.hpp"
#include "Components/Components.h"

class MapComponent : public Component {
public:
    explicit MapComponent(
        int num_walls, int num_obstacles, float cubesize
    );
    ~MapComponent();
    void init() override;
    void update() override;
    void draw() override;
private:
    Vector2D _size;
    std::vector<Entity *> Walls;
public:
    const std::vector<Entity *> & getWalls() const;
    const std::vector<Entity *> &getObstacles() const;
private:
    std::vector<Entity *> Obstacles;
    int numWalls;
    int numObstacles;
    float cubesize;
    TransformComp *transform;
};

#endif //MAPCOMPONENT_HPP