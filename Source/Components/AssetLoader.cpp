/*
** EPITECH PROJECT, 2024
** AssetLoader.cpp
** File description:
** Created by Leo Fabre
*/
#include "Entity.hpp"
#include "AssetLoader.hpp"

//todo: if an asset is not found, exit(0)
AssetLoader::AssetLoader()
    : PlayerModel("./Assets/Models/steve/steve.gltf", "./Assets/Models/steve/skin.png", .5),
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
      ButtonClick("Assets/sounds/button_click.wav"),
      Volume(1),
      FullFireSprite("./Assets/Textures/FullFire.png"),
      BombUpSprite("./Assets/Textures/BombUp.png"),
      SkateSprite("./Assets/Textures/Skate.png"),
      SoftBlockPassSprite("./Assets/Textures/SoftBlockPass.png"),
      FireUpSprite("./Assets/Textures/FireUp.png"),
      MainLogo("./Assets/Textures/mainlogo.png"),
      MenuASprite("./Assets/Textures/menu/sky.png"),
      MenuBSprite("./Assets/Textures/menu/cloud.png"),
      MenuCSprite("./Assets/Textures/menu/mountain.png"),
      MenuDSprite("./Assets/Textures/menu/pine1.png"),
      MenuESprite("./Assets/Textures/menu/pine2.png"),
      loadGame(false)
{
}

AssetLoader::~AssetLoader()
{
    PlayerModel.Unload();
    StoneCubeModel.Unload();
    BombModel.Unload();
    ObstacleModel.Unload();
    ExplosionModel.Unload();
    ExplosionAnim.Unload();
    FloorModel.Unload();
    FullFireModel.Unload();
    BombUpModel.Unload();
    SkateModel.Unload();
    SoftBlockPassModel.Unload();
    FireUpModel.Unload();
    ExplosionSound.Unload();
    WalkingSound.Unload();
    PowerupPickUp.Unload();
    PowerupGenerated.Unload();
    PlayerHurt.Unload();
    PlayerDead.Unload();
    ButtonClick.Unload();
    FullFireSprite.Unload();
    BombUpSprite.Unload();
    SkateSprite.Unload();
    SoftBlockPassSprite.Unload();
    FireUpSprite.Unload();
    MainLogo.Unload();
    MenuASprite.Unload();
    MenuBSprite.Unload();
    MenuCSprite.Unload();
    MenuDSprite.Unload();
    MenuESprite.Unload();
}

void AssetLoader::init()
{
    Component::init();
    entity->SetDontDestroyOnLoad(true);
}
