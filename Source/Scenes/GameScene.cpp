/*
** EPITECH PROJECT, 2023
** bomberman
** File description:
** Created by Adrien Courbebaisse
*/
#include "ECS/Manager.hpp"
#include "Components/Components.h"
#include "MapComponent.hpp"

void Manager::loadGameScene()
{
    GenerateMap();
    auto myEnt = getEntByName("gamelogic");
    myEnt->addComponent<GameLogicComp>();

    //TODO PUT VECTOR 3D ROTATE IN TRANSFORM
    /*auto &myEnt = addEntity("Player");
    myEnt.addComponent<TransformComp>(Vector3D(0, -28, -30));
    myEnt.addComponent<ModelComp>("./rsc/Models/mrfixit.iqm", Green, 0.77);
    myEnt.getComponent<ModelComp>().rotate({90, 0, 0});
    myEnt.addComponent<BasicCubeComp>(Vector3D::One().Multiply(2));
    myEnt.addComponent<MovementComp>(EInputType::Keyboard,
        PlayerNum::PlayerOne);*/
}

void Manager::GenerateMap()
{
    Vector2D mapSize(13, 11);
    auto &MapEntity = addEntity("mapRoot");
    auto &mapTransform =
        MapEntity.addComponent<TransformComp>(Vector3D(0, -30, 0));
    auto &mapComp = MapEntity.addComponent<MapComponent>( 7, 59);
    MapEntity.addComponent<BasicCubeComp>(Vector3D::One().Multiply(2));

    float cubeScale = 2;
    std::cout << "init map. size : " << mapSize << std::endl;

    std::cout << "Making floor." << std::endl;
    for (int z = 0; (float) z < mapSize.y; ++z) {
        Vector3D pos(0, mapTransform.position.y,
            (float) mapTransform.position.z + z * cubeScale);
        for (int x = 0; (float) x < mapSize.x; ++x) {
            pos.x = (float) x * cubeScale;
            Entity *cube = &addEntity(
                std::to_string(pos.x).append(std::to_string(pos.y)));
            cube->addComponent<TransformComp>(
                Vector3D(-mapSize.x, 0, -mapSize.y * 3).Add(pos));
            cube->addComponent<BasicCubeComp>(
                Vector3D::One().Multiply(cubeScale),
                Colors::Black, Colors::Black);
        }
    }
    std::cout << "Making Walls." << std::endl;
    for (auto &wallPos:mapComp.getWalls()) {
        Vector3D pos(
            wallPos.x * cubeScale,
            mapTransform.position.y + cubeScale,
            (float) mapTransform.position.z + wallPos.y * cubeScale);
        Entity *cube =
            &addEntity(std::to_string(pos.x).append(std::to_string(pos.y)));
        cube->addComponent<TransformComp>(
            Vector3D(-mapSize.x, 0, -mapSize.y * 3).Add(pos));
        cube->addComponent<BasicCubeComp>(
            Vector3D::One().Multiply(cubeScale),
            Colors::RayWhite, Colors::Black);
        cube->addGroup(Walls);
    }
    std::cout << "Making Obstacles." << std::endl;
    for (auto &obsPos : mapComp.getObstacles()) {
        Vector3D pos(
            obsPos.x * cubeScale,
            mapTransform.position.y + cubeScale,
            (float) mapTransform.position.z + obsPos.y * cubeScale);
        Entity *cube =
            &addEntity(std::to_string(pos.x).append(std::to_string(pos.y)));
        cube->addComponent<TransformComp>(
            Vector3D(-mapSize.x, 0, -mapSize.y * 3).Add(pos));
        cube->addComponent<BasicCubeComp>(
            Vector3D::One().Multiply(cubeScale),
            Colors::Gray, Colors::Black);
        cube->addGroup(Obstacles);
    }
}
