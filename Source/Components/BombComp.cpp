/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by Achille Bourgault
*/

#include <Component.hpp>
#include <GUI/AnimatedSprite2D.hpp>
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
    model =
        &entity->addComponent<ModelComp>("./rsc/Models/bomb/Bombout.obj", Blue,
            6);
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
    auto &testBoom = entity->_mgr.addEntity("boom");
    testBoom.addComponent<TransformComp>(_transform->position);
    std::cout << "position : " << _transform->position << std::endl;
    testBoom.addComponent<AnimatedSprite2D>("./rsc/explosion.png",
        Vector2D{5, 5});
    testBoom.addGroup(Particles);
    entity->destroy();
}

