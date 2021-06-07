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
      model(nullptr),
      spawnTime(std::time(nullptr)),
      hasExploded(false),
      particlesCleared(false)
{
}

void BombComp::init()
{
    Component::init();
    _transform = &entity->getComponent<TransformComp>();
    if (!_transform)
        _transform = &entity->addComponent<TransformComp>();
    model =
        &entity->addComponent<ModelComp>("./rsc/Models/bomb/Bombout.obj", Blue,
            6);
}

void BombComp::update()
{
    Component::update();
    auto timeAlive = std::difftime(std::time(nullptr), spawnTime);
    if (timeAlive > 3 && !hasExploded) {
        hasExploded = true;
        explode();
    }
    if (timeAlive > 4 && !particlesCleared) {
        std::cout << "coucou" << std::endl;
        particlesCleared = true;
        for (auto &item : particles) {
            item->destroy();
            std::cout << "destroyed particle" << std::endl;
        }
        std::cout << "destroyed bomb" << std::endl;
        entity->destroy();
    }
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

    pos.z -= 2;
    SpawnParticle(pos);
    pos.z -= 2;
    SpawnParticle(pos);
    pos.z -= 2;
    SpawnParticle(pos);
    pos.z = _transform->position.z;

    pos.z += 2;
    SpawnParticle(pos);
    pos.z += 2;
    SpawnParticle(pos);
    pos.z += 2;
    SpawnParticle(pos);
    pos.z = _transform->position.z;
}

void BombComp::SpawnParticle(Vector3D &pos)
{
    auto &testBoom = entity->_mgr.addEntity("boom");
    testBoom.addComponent<TransformComp>(pos);
    testBoom.addComponent<BasicCubeComp>(Vector3D::One().Multiply(2));
    testBoom.addGroup(Particles);
    particles.emplace_back(&testBoom);
}

