/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by Achille Bourgault
*/

#include <Component.hpp>
#include "BombComp.hpp"
#include "Manager.hpp"

BombComp::BombComp(Colors color)
    : _color(color),
      _transform(nullptr),
      _cube(nullptr),
      model(nullptr),
      spawnTime(std::time(nullptr))
{
}

void BombComp::init()
{
    Component::init();
    _transform = &entity->getComponent<TransformComp>();
    if (!_transform)
        _transform = &entity->addComponent<TransformComp>();
    //TODO : replace cube by bomb model
//    _cube = &entity->addComponent<BasicCubeComp>(Vector3D::One().Multiply(2));
    model = &entity->addComponent<ModelComp>("./rsc/Models/bomb/Bombout.obj", Blue, 10);
//    model = &entity->addComponent<ModelComp>("./rsc/Models/bomberman.obj", 1);
//    bombModel = LoadModel("./rsc/Models/bomb/mrfixit.iqm");
//    texture = LoadTexture("./rsc/Models/bomb/Albedo.png");
//    bombModel.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
}

void BombComp::update()
{
    Component::update();
    auto timeAlive = std::difftime(std::time(nullptr), spawnTime);
    if (timeAlive > 3)
        explode();
}

void BombComp::draw()
{
    Component::draw();
//    DrawModel(bombModel, _transform->position, 10000, BLUE);
}

void BombComp::explode()
{
    std::cout << "BOOM !" << std::endl;
    //todo : spawn explosion sprites in a cross pattern
    entity->destroy();
}

