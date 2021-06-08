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
    transform = &entity->getComponent<TransformComp>();
    if (!transform)
        transform = &entity->addComponent<TransformComp>(-13, -28, -26);
    //    place_root_visualizer();
    gen_floor();
    //generate walls
    gen_walls();
    //generate  obstacles
    gen_obstacles();
}

void MapComponent::gen_obstacles()
{
    Vector3D maxPos(transform->position.x + (_size.x * cubesize) - cubesize,
        transform->position.y,
        transform->position.z + (_size.y * cubesize) - cubesize);
    for (int i = 0; i < numObstacles; ++i) {
        Vector3D pos = Vector3D::Zero();
        do {
            pos.x = transform->position.x +
                (Random::Range(0, _size.x - 1) * cubesize);
            pos.y = transform->position.y;
            pos.z = transform->position.z +
                (Random::Range(0, _size.y - 1) * cubesize);
        } while (positionAlreadyExists(pos) || positionIsInCorner(pos));
        std::cout << "pos : " << pos << std::endl;
        std::cout << "map pos : " << transform->position << std::endl;
        auto newEnt = &entity->_mgr.addEntity("Obstacle:" +
            std::to_string(pos.x) + ":" + std::to_string(pos.z));
        newEnt->addGroup(GroupLabel::Obstacles);
        newEnt->addComponent<TransformComp>(pos);
        newEnt->addComponent<BasicCubeComp>(
            Vector3D::One().Multiply(2), Gray, Black);
        Obstacles.emplace_back(newEnt);
    }
}

bool MapComponent::positionAlreadyExists(const Vector3D &pos)
{
    return (std::find_if(
        Walls.begin(), Walls.end(),
        [pos](const Entity *ent) {
            return ent->getComponent<TransformComp>().position == pos;
        }) != Walls.end())
        ||
        (std::find_if(Obstacles.begin(), Obstacles.end(),
            [pos](const Entity *ent) {
                return ent->getComponent<TransformComp>().position == pos;
            }) != Obstacles.end());
}

void MapComponent::gen_walls()
{
    for (int x = cubesize;
        x < (_size.x - 1) * cubesize; x += static_cast<int>(cubesize * 2)) {
        for (int z = cubesize;
            z < (_size.y - 1) * cubesize; z += static_cast<int>(cubesize * 2)) {
            auto newEnt = &entity->_mgr.addEntity(
                "Wall:" + std::to_string(x) + ":" + std::to_string(z));
            newEnt->addGroup(GroupLabel::Walls);
            newEnt->addComponent<TransformComp>(x + transform->position.x,
                transform->position.y, transform->position.z + z);
            newEnt->addComponent<BasicCubeComp>(
                Vector3D::One().Multiply(2), RayWhite, Black);
            Walls.emplace_back(newEnt);
        }
    }
}

void MapComponent::gen_floor()
{
    for (int x = 0;
        x < (_size.x) * cubesize;
        x += static_cast<int>(cubesize)) {
        for (int z = 0;
            z < (_size.y) * cubesize;
            z += static_cast<int>(cubesize)) {
            Vector3D pos(x + transform->position.x,
                transform->position.y - cubesize,
                transform->position.z + z);
            auto newEnt = &entity->_mgr.addEntity("Wall:" +
                std::to_string(x) + ":" + std::to_string(z));
            newEnt->addGroup(GroupLabel::Floor);
            newEnt->addComponent<TransformComp>(pos);
            newEnt->addComponent<BasicCubeComp>(
                Vector3D::One().Multiply(2), Black, Black);
        }
    }
}

void MapComponent::place_root_visualizer()
{
    auto newEnt = &entity->_mgr.addEntity(
        "root_visualiser");
    newEnt->addGroup(GroupLabel::Floor);
    newEnt->addComponent<TransformComp>(transform->position);
    newEnt->addComponent<BasicCubeComp>(
        Vector3D::One().Multiply(2), Green, Black);
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

bool MapComponent::positionIsInCorner(Vector3D pos)
{
    Vector3D maxPos(transform->position.x + (_size.x * cubesize) - cubesize,
        transform->position.y,
        transform->position.z + (_size.y * cubesize) - cubesize);
    Vector3D origin = transform->position;
    //upper left
    if (pos.x == origin.x && pos.z == origin.z) return true;
    if (pos.x == origin.x + cubesize && pos.z == origin.z) return true;
    if (pos.x == origin.x && pos.z == origin.z + cubesize) return true;

    //lower left
    if (pos.x == origin.x && pos.z == maxPos.z) return true;
    if (pos.x == origin.x + cubesize && pos.z == maxPos.z) return true;
    if (pos.x == origin.x && pos.z == maxPos.z - cubesize) return true;
    //lower right
    if (pos.x == maxPos.x && pos.z == maxPos.z) return true;
    if (pos.x == maxPos.x && pos.z == maxPos.z - cubesize) return true;
    if (pos.x == maxPos.x - cubesize && pos.z == maxPos.z) return true;
    //upper right
    if (pos.x == maxPos.x && pos.z == origin.z) return true;
    if (pos.x == maxPos.x - cubesize && pos.z == origin.z) return true;
    if (pos.x == maxPos.x && pos.z == origin.z + cubesize) return true;

    return false;
}
