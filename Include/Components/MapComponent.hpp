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
        int num_walls, int num_obstacles
    );
    ~MapComponent();
    void init() override;
    void update() override;
    void draw() override;
private:
    Vector2D _size;
    std::vector<Vector2D> Walls;
public:
    const std::vector<Vector2D> &getWalls() const;
    const std::vector<Vector2D> &getObstacles() const;
private:
    std::vector<Vector2D> Obstacles;
    int numWalls;
    int numObstacles;
    bool InCorner(const Vector2D& vector_2_d);
};

#endif //MAPCOMPONENT_HPP