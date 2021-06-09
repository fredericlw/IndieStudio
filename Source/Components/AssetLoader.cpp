/*
** EPITECH PROJECT, 2024
** AssetLoader.cpp
** File description:
** Created by Leo Fabre
*/
#include "AssetLoader.hpp"

AssetLoader::AssetLoader()
    : PlayerModel("./Assets/Models/Bomberman/Bomberman.glb", 1),
      StoneCubeModel("./Assets/Models/StoneCube/StoneCube.glb", 1),
      BombModel("./Assets/Models/bomb/Bombout.obj", 6),
      ObstacleModel("./Assets/Models/Obstacle/Obstacle.glb", 1),
      ExplosionModel("./Assets/Models/Explosion/Explosion.glb", 1.5),
      ExplosionAnim("./Assets/Models/Explosion/Explosion.glb", ExplosionModel),
      FloorModel("./Assets/Models/Floor/floorUnit.glb", 1)
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
