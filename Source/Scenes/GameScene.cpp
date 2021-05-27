/*
** EPITECH PROJECT, 2023
** bomberman
** File description:
** Created by Adrien Courbebaisse
*/
#include "ECS/Manager.hpp"
#include "Components/Components.h"
#include "MapComponent.hpp"

void Manager::AddCubeZER()
{
    auto &monCUB = addEntity("Gro KUBE");
    monCUB.addComponent<TransformComp>(Vector3D(0, -38, -30));
    monCUB.addComponent<BasicCubeComp>(Vector3D::One().Multiply(2));
    monCUB.addComponent<MovementComp>(EInputType::Keyboard,
        PlayerNum::PlayerOne);
}

void Manager::GenerateMap()
{
    Vector2D mapSize(20, 20);
    auto &MapEntity = addEntity("mapRoot");
    auto &transform =
        MapEntity.addComponent<TransformComp>(Vector3D(0, -20, -20));
    auto &mapComp = MapEntity.addComponent<MapComponent>(mapSize, 7, 7);
    //    MapEntity.addComponent<BasicCubeComp>(Vector3D::One().Multiply(5));

    float cubeScale = 2;
    std::cout << "init map. size : " << mapSize << std::endl;

    std::cout << "Making floor." << std::endl;
    for (int z = 0; (float) z < mapSize.y; ++z) {
        Vector3D pos(0, transform.position.y,
            (float) z * cubeScale);
        for (int x = 0; (float) x < mapSize.x; ++x) {
            pos.x = (float) x * cubeScale;
            Entity *cube =
                &addEntity(std::to_string(pos.x).append(std::to_string(pos.y)));
            cube->addComponent<TransformComp>(
                Vector3D(-mapSize.x, -20, -mapSize.y * 3).Add(pos));
            cube->addComponent<BasicCubeComp>(
                Vector3D::One().Multiply(cubeScale),
                Colors::Black, Colors::RayWhite);
        }
    }

    return;
    //todo : this is a test to find offset to apply to walls and obstacles
    {
        Entity *cube = &addEntity("test");
        Vector3D pos(0, transform.position.y - 17,(float) 0 * cubeScale);
        cube->addComponent<TransformComp>(
            Vector3D(-mapSize.x, -20, -mapSize.y * 4));
        cube->addComponent<BasicCubeComp>(
            Vector3D::One().Multiply(cubeScale),
            Colors::RayWhite, Colors::Black);
    }
    std::cout << "Making Walls." << std::endl;
    for (auto &wallPos:mapComp.getWalls()) {
        Vector3D pos(transform.position);
        //        pos.x = (float) wallPos.x * cubeScale;
        //        pos.y = (float) wallPos.y * cubeScale;
        std::cout << "wall pos " << wallPos << std::endl;
        Entity *cube =
            &addEntity(std::to_string(pos.x).append(std::to_string(pos.y)));
        cube->addComponent<TransformComp>(
            Vector3D(-mapSize.x, -20, -mapSize.y * 4).Add(pos));
        cube->addComponent<BasicCubeComp>(
            Vector3D::One().Multiply(cubeScale),
            Colors::RayWhite, Colors::Black);
    }
}

Manager::SceneType Manager::getNextSceneToLoad() const
{
    return nextSceneToLoad;
}

void Manager::setNextSceneToLoad(Manager::SceneType next_scene_to_load)
{
    nextSceneToLoad = next_scene_to_load;
}

void Manager::setAlive(bool alive)
{
    Manager::alive = alive;
}
