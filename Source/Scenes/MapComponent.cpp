/*
** EPITECH PROJECT, 2024
** MapComponent.cpp
** File description:
** Created by Leo Fabre
*/
#include <raylib_encap/Math/Random.hpp>
#include "MapComponent.hpp"
#include "ECS/Entity.hpp"
#include "ECS/Manager.hpp"

MapComponent::MapComponent(
    int num_walls, int num_obstacles
)
    : _size(Vector2D(13, 13)),
      numWalls(num_walls),
      numObstacles(num_obstacles)
{
    //generate walls
    for (int i = 0; i < numWalls; ++i) {
        auto x = (float) Random::Range(0, (int) _size.x - 1);
        auto y = (float) Random::Range(0, (int) _size.y - 1);
        Walls.emplace_back(Vector2D(x, y));
    }
    //generate  obstacles
    for (int i = 0; i < numObstacles; ++i) {
        Vector2D pos = Vector2D::Zero();
        do {
            pos.x = (float) Random::Range(0, (int) _size.x - 1);
            pos.y = (float) Random::Range(0, (int) _size.y - 1);
        } while (std::find(Walls.begin(), Walls.end(), pos) != Walls.end());
        //random coords until not on a wall
        Obstacles.emplace_back(pos);
    }
}

MapComponent::~MapComponent()
{
}

void MapComponent::init()
{
    Component::init();
}

void MapComponent::update()
{
    Component::update();
}

void MapComponent::draw()
{
    Component::draw();
}

const std::vector<Vector2D> &MapComponent::getWalls() const
{
    return Walls;
}

const std::vector<Vector2D> &MapComponent::getObstacles() const
{
    return Obstacles;
}
