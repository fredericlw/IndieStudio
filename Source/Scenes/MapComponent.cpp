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
        Vector2D pos = Vector2D::Zero();
        do {
            pos.x = (float) Random::Range(0, (int) _size.x - 1);
            pos.y = (float) Random::Range(0, (int) _size.y - 1);
        } while (std::find(Walls.begin(), Walls.end(), pos) != Walls.end()
            && /*forbidden places (corners)*/ !InCorner(pos));
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

bool MapComponent::InCorner(Vector2D pos)
{
    if (pos == Vector2D::Zero()
        || pos == Vector2D(0, 1)
        || pos == Vector2D(1, 0)
        || pos == Vector2D(_size.x, _size.y)
        || pos == Vector2D(_size.x - 2, _size.y)
        || pos == Vector2D(_size.x, _size.y - 2)
        || pos == Vector2D(0, _size.y)
        || pos == Vector2D(1, _size.y)
        || pos == Vector2D(0, _size.y - 2)
        || pos == Vector2D(_size.x, 0)
        || pos == Vector2D(_size.x, 1)
        || pos == Vector2D(_size.x - 2, 0)
        )
        return true;
    return false;
}
