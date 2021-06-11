/*
** EPITECH PROJECT, 2023
** bomberman
** File description:
** Created by Adrien Courbebaisse
*/
#include <GUI/PauseMenuComp.hpp>
#include "ECS/Manager.hpp"
#include "Components/Components.h"
#include "Components/Logic/MapComponent.hpp"

void Manager::loadGameScene()
{
    //warning : Keep this order !
    auto gl = getEntByName("gamelogic");
    GenerateMap();
    gl->addComponent<GameLogicComp>();
    gl->addComponent<PauseMenuComp>();
}

void Manager::GenerateMap()
{
    Vector2D mapSize(13, 11);
    auto &MapEntity = addEntity("mapRoot");
    auto &mapTransform =
        MapEntity.addComponent<TransformComp>(Vector3D(-12, -28, -20));
    auto &mapComp = MapEntity.addComponent<MapComponent>( 7, 59, 2);
    MapEntity.addComponent<BasicCubeComp>(Vector3D::One().Multiply(2));
}
