/*
** EPITECH PROJECT, 2023
** bomberman
** File description:
** Created by Adrien Courbebaisse
*/
#include "ECS/Manager.hpp"
#include "Components/Components.h"
#include "Components/Logic/MapComponent.hpp"

void Manager::loadGameScene()
{
    //warning : Keep this order !
    auto myEnt = getEntByName("gamelogic");
    myEnt->addComponent<AssetLoader>();
    GenerateMap();
    myEnt->addComponent<GameLogicComp>();

    //TODO PUT VECTOR3D::ROTATE() IN TRANSFORM
}

void Manager::GenerateMap()
{
    Vector2D mapSize(13, 11);
    auto &MapEntity = addEntity("mapRoot");
    auto &mapTransform =

        MapEntity.addComponent<TransformComp>(Vector3D(-12, -30, -34));
    auto &mapComp = MapEntity.addComponent<MapComponent>( 7, 59, 2);
    MapEntity.addComponent<BasicCubeComp>(Vector3D::One().Multiply(2));

    float cubeScale = 2;
    std::cout << "init map. size : " << mapSize << std::endl;
    return;
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
            cube->addGroup(Floor);
        }
    }
}
