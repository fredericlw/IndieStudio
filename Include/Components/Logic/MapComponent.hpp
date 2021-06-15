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
    std::vector<Entity *> Walls;
    std::vector<Entity *> Obstacles;
private:
    Vector2D _size;
private:
    int numWalls;
    int numObstacles;
    float cubesize;
    TransformComp *transform;
    void place_root_visualizer();
    void gen_walls();
    void gen_obstacles();
    void gen_floor();
    bool positionAlreadyExists(const Vector3D &pos);
    bool positionIsInCorner(Vector3D pos);
};

#endif //MAPCOMPONENT_HPP