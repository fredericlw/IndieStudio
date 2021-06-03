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
    : _size(Vector2D(13, 11)),
      numWalls(num_walls),
      numObstacles(num_obstacles)
{
    //generate walls
    for (int x = 1; x < _size.x - 1; x += 2) {
        for (int y = 1; y < _size.y - 1; y += 2) {
            Walls.emplace_back(Vector2D((float) x, (float) y));
        }
    }
    //generate  obstacles
    for (int i = 0; i < numObstacles; ++i) {
        Vector2D pos;
        do {
            pos.x = (float) Random::Range(0, (int) _size.x - 1);
            pos.y = (float) Random::Range(0, (int) _size.y - 1);
        } while (InCorner(pos) ||
            std::find(Walls.begin(), Walls.end(), pos) != Walls.end());
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

bool MapComponent::InCorner(const Vector2D &pos)
{
    //upper left
    if (pos.x == 0 && pos.y == 0) return true;
    if (pos.x == 1 && pos.y == 0) return true;
    if (pos.x == 0 && pos.y == 1) return true;
    //lower left
    if (pos.x == 0 && pos.y == _size.y - 1) return true;
    if (pos.x == 1 && pos.y == _size.y - 1) return true;
    if (pos.x == 0 && pos.y == _size.y - 2) return true;
    //lower right
    if (pos.x == _size.x - 1 && pos.y == _size.y - 1) return true;
    if (pos.x == _size.x - 1 && pos.y == _size.y - 2) return true;
    if (pos.x == _size.x - 2 && pos.y == _size.y - 1) return true;
    //upper right
    if (pos.x == _size.x - 1 && pos.y == 0) return true;
    if (pos.x == _size.x - 2 && pos.y == 0) return true;
    if (pos.x == _size.x - 1 && pos.y == 1) return true;
    return false;
}
