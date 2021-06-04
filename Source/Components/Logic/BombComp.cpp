/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by Achille Bourgault
*/

#include <Component.hpp>
#include <GUI/AnimatedSprite.hpp>
#include "Components/Logic/BombComp.hpp"
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
    GenerateParticles();
    entity->destroy();
}

void BombComp::GenerateParticles()
{
    //TODO : this is bad code pls fix
    Vector3D pos(_transform->position);

    SpawnParticle(pos);

    pos.x += 2;
    SpawnParticle(pos);
    pos.x += 2;
    SpawnParticle(pos);
    pos.x += 2;
    SpawnParticle(pos);
    pos.x = _transform->position.x;

    pos.x -= 2;
    SpawnParticle(pos);
    pos.x -= 2;
    SpawnParticle(pos);
    pos.x -= 2;
    SpawnParticle(pos);
    pos.x = _transform->position.x;

    pos.y -= 2;
    SpawnParticle(pos);
    pos.y -= 2;
    SpawnParticle(pos);
    pos.y -= 2;
    SpawnParticle(pos);
    pos.y = _transform->position.y;

    pos.y += 2;
    SpawnParticle(pos);
    pos.y += 2;
    SpawnParticle(pos);
    pos.y += 2;
    SpawnParticle(pos);
    pos.y = _transform->position.y;
}

void BombComp::SpawnParticle(Vector3D &pos)
{
    auto &testBoom = entity->_mgr.addEntity("boom");
    testBoom.addComponent<TransformComp>(pos);
    testBoom.addComponent<AnimatedSprite>("./rsc/explosion.png",
        Vector2D{5, 5});
    testBoom.addGroup(Particles);
}

