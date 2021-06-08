/*
** EPITECH PROJECT, 2024
** MapComponent.cpp
** File description:
** Created by Leo Fabre
*/
#include <raylib_encap/Math/Random.hpp>
#include "Components/Logic/MapComponent.hpp"
#include "ECS/Entity.hpp"
#include "ECS/Manager.hpp"

MapComponent::MapComponent(
    int num_walls, int num_obstacles, float cubesize
)
    : _size(Vector2D(13, 11)),
      numWalls(num_walls),
      numObstacles(num_obstacles),
      cubesize(cubesize)
{
}

MapComponent::~MapComponent()
{
}

void MapComponent::init()
{
    Component::init();
    //generate walls
    transform = &entity->getComponent<TransformComp>();
    if (!transform)
        transform = &entity->addComponent<TransformComp>(-13, -28, -26);
    auto newEnt = &entity->_mgr.addEntity(
        "puto");
    newEnt->addGroup(GroupLabel::Walls);
    newEnt->addComponent<TransformComp>(transform->position);
    newEnt->addComponent<BasicCubeComp>(
        Vector3D::One().Multiply(2), Colors::RayWhite, Colors::Black);
    for (int x = cubesize; x < (_size.x - 1) * cubesize; x += static_cast<int>(cubesize)) {
        for (int z = cubesize; z < (_size.y - 1) * cubesize; z += static_cast<int>(cubesize)) {
            auto newEnt = &entity->_mgr.addEntity(
                "Wall:" + std::to_string(x) + ":" + std::to_string(z));
            newEnt->addGroup(GroupLabel::Walls);
            newEnt->addComponent<TransformComp>(x + transform->position.x, transform->position.y, transform->position.z + z);
            newEnt->addComponent<BasicCubeComp>(
                Vector3D::One().Multiply(2), Colors::RayWhite, Colors::Black);
            Walls.emplace_back(newEnt);
        }
    }
    //generate  obstacles
    for (int i = 0; i < numObstacles; ++i) {
        Vector3D pos = Vector3D::Zero();
        do {
            pos.x = (float) Random::Range(0, (int) _size.x - 1);
            pos.y = transform->position.y - 2;
            if (pos.x == 0 || pos.x == _size.x - 1)
                pos.z = (float) Random::Range(1, (int) _size.y - 2);
            else
                pos.z = (float) Random::Range(0, (int) _size.y - 1);
        } while (std::find_if(
            Walls.begin(), Walls.end(),
            [pos](const Entity *ent) {return ent->getComponent<TransformComp>().position == pos;}) != Walls.end());
            auto newEnt = &entity->_mgr.addEntity(
                "Obstacle:" + std::to_string(pos.x) + ":" +
                    std::to_string(pos.z));
            newEnt->addGroup(GroupLabel::Walls);
            newEnt->addComponent<TransformComp>(
                pos.x, transform->position.y, pos.z);
            newEnt->addComponent<BasicCubeComp>(
                Vector3D::One().Multiply(2), Colors::RayWhite, Colors::Black);
            Obstacles.emplace_back(newEnt);
    }
}

void MapComponent::update()
{
    Component::update();
}

void MapComponent::draw()
{
    Component::draw();
}

const std::vector<Entity *> &MapComponent::getWalls() const
{
    return Walls;
}

const std::vector<Entity *> &MapComponent::getObstacles() const
{
    return Obstacles;
}