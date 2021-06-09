/*
** EPITECH PROJECT, 2024
** AssetLoader.cpp
** File description:
** Created by Leo Fabre
*/
#include "AssetLoader.hpp"

AssetLoader::AssetLoader()
    : PlayerModel("./Assets/Models/cus/player.gltf",  .5),
      StoneCubeModel("./Assets/Models/StoneCube/StoneCube.glb", 1),
      BombModel("./Assets/Models/bomb/Bombout.obj", 6),
      ObstacleModel("./Assets/Models/Obstacle/Obstacle.glb", 1),
      ExplosionModel("./Assets/Models/Explosion/Explosion.glb", 1.5),
      ExplosionAnim("./Assets/Models/Explosion/Explosion.glb", ExplosionModel),
      FloorModel("./Assets/Models/Floor/floorUnit.glb", 1),
      FireupModel("./Assets/Models/powerups/FireUp.gltf", 1.5),
      BombupModel("./Assets/Models/powerups/BombUp.gltf", 1.5),
      SkateModel("./Assets/Models/powerups/Skate.gltf", 1.5),
      SoftBlockPassModel("./Assets/Models/powerups/SoftBlockPass.gltf", 1.5)
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
