/*
** EPITECH PROJECT, 2024
** AssetLoader.cpp
** File description:
** Created by Leo Fabre
*/
#include "AssetLoader.hpp"

AssetLoader::AssetLoader()
    : PlayerModel("./rsc/Models/mrfixit.iqm", .5),
      StoneCubeModel("./rsc/Models/StoneCube/StoneCube.glb", 1),
      BombModel("./rsc/Models/bomb/Bombout.obj", 6),
      ObstacleModel("./rsc/Models/Obstacle/Obstacle.glb", 1)
{
}

AssetLoader::~AssetLoader()
{
    PlayerModel.Unload();
    StoneCubeModel.Unload();
    BombModel.Unload();
}

void AssetLoader::init()
{
    Component::init();
}
