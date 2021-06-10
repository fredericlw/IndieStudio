/*
** EPITECH PROJECT, 2024
** AssetLoader.cpp
** File description:
** Created by Leo Fabre
*/
#include "Entity.hpp"
#include "AssetLoader.hpp"

AssetLoader::AssetLoader()
    : PlayerModel("./Assets/Models/cus/player.gltf",  .5),
      StoneCubeModel("./Assets/Models/StoneCube/StoneCube.glb", 1),
      BombModel("./Assets/Models/bomb/Bombout.obj", 6),
      ObstacleModel("./Assets/Models/Obstacle/Obstacle.glb", 1),
      ExplosionModel("./Assets/Models/Explosion/Explosion.glb", 1.5),
      ExplosionAnim("./Assets/Models/Explosion/Explosion.glb", ExplosionModel),
      FloorModel("./Assets/Models/Floor/floorUnit.glb", 1),
      FullFireModel("./Assets/Models/powerups/FullFire.gltf", 1.5),
      BombUpModel("./Assets/Models/powerups/BombUp.gltf", 1.5),
      SkateModel("./Assets/Models/powerups/Skate.gltf", 1.5),
      SoftBlockPassModel("./Assets/Models/powerups/SoftBlockThrough.gltf", 1.5),
      FireUpModel("./Assets/Models/powerups/FireUp.gltf", 1.5),
      ExplosionSound("Assets/sounds/explosion.wav"),
      WalkingSound("Assets/sounds/walking.mp3"),
      PowerupPickUp("Assets/sounds/powerup_pick_up.wav"),
      PowerupGenerated("Assets/sounds/powerup_generated.wav"),
      PlayerHurt("Assets/sounds/player_hurt.wav"),
      PlayerDead("Assets/sounds/player_dead.wav"),
      Volume(1),
      FullFireSprite("./Assets/Textures/FullFire.png", White),
      BombUpSprite("./Assets/Textures/BombUp.png", White),
      SkateSprite("./Assets/Textures/Skate.png", White),
      SoftBlockPassSprite("./Assets/Textures/SoftBlockPass.png", White),
      FireUpSprite("./Assets/Textures/FireUp.png", White)
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
    entity->SetDontDestroyOnLoad(true);
}
