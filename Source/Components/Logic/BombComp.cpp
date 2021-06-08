/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by Achille Bourgault
*/

#include <Component.hpp>
#include <GUI/AnimatedSprite.hpp>
#include <Logic/MapComponent.hpp>
#include <raylib_encap/Math/Random.hpp>
#include "Components/Logic/BombComp.hpp"
#include "Manager.hpp"
#include "raylib_encap/ECube.hpp"
#include "raylib_encap/Math/CubeCollider.hpp"
#include "Entity.hpp"

BombComp::BombComp(Colors color, Player *owner)
    : _color(color),
      _transform(nullptr),
      model(nullptr),
      spawnTime(std::time(nullptr)),
      hasExploded(false),
      particlesCleared(false),
      _owner(owner)
{
    _explosion_sound = new ESound("rsc/sounds/explosion.wav");
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
        explode();
    }
    if (timeAlive > 4 && !particlesCleared) {
        std::cout << "coucou" << std::endl;
        particlesCleared = true;
        for (auto &item : particles) {
            item->destroy();
        }
        entity->destroy();
        _owner->droppedBombs--;
    }
}

void BombComp::draw()
{
    Component::draw();
}

void BombComp::explode()
{
    hasExploded = true;
    model->SetVisibility(false);
    std::cout << "BOOM !" << std::endl;
    _explosion_sound->playSound();
    GenerateParticles();
}

void BombComp::GenerateParticles()
{
    SpawnParticle(_transform->position);
    spreadExplosion(Right);
    spreadExplosion(Left);
    spreadExplosion(Up);
    spreadExplosion(Down);
}

bool BombComp::SpawnParticle(Vector3D &pos)
{
    //will return true if hit a wall or an obstacle (hurting players and destroying obstacle)
    checkPlayer(pos);
    if (checkWall(pos))
        return true;
    auto &particleEnt = entity->_mgr.addEntity("boom_particle");
    particleEnt.addComponent<TransformComp>(pos);
    //todo: if on obstacle, change color
    particleEnt.addComponent<BasicCubeComp>(Vector3D::One().Multiply(2));
    particleEnt.addGroup(Particles);
    particles.emplace_back(&particleEnt);
    if (checkObstacle(pos))
        return true;
    return false;
}

void BombComp::spreadExplosion(Way way)
{
    Vector3D pos(_transform->position);
    for (int i = 0; i < 3; i++) {
        switch (way) {
        case Left:
            pos.x -= 2;
            break;
        case Down:
            pos.z += 2;
            break;
        case Up:
            pos.z -= 2;
            break;
        case Right:
            pos.x += 2;
            break;
        }
        if (SpawnParticle(pos)) break;
    }
//    switch (way) {
//    case Left:
//    case Right:
//        pos.x = _transform->position.x;
//        break;
//    case Down:
//    case Up:
//        pos.z = _transform->position.z;
//        break;
//    }
}

bool BombComp::checkObstacle(Vector3D pos)
{
    auto obstacles = entity->_mgr.getEntitiesInGroup(Obstacles);
    for (auto &obstacle : obstacles) {
        Vector3D obstaclePos = obstacle->getComponent<TransformComp>().position;
        if (obstaclePos == pos) {
            obstacle->destroy();
            if (Random::Range(0, 1) == 1) {
                //TODO : Spawn a random powerup here
                std::cout << "Spawning powerup !" << std::endl;
            }
            std::cout << "hit obstacle !" << std::endl;
            return true;
        }
    }
    return false;
}

bool BombComp::checkWall(Vector3D pos)
{
    auto walls = entity->_mgr.getEntitiesInGroup(Walls);
    for (auto &wall : walls) {
        Vector3D wallPos = wall->getComponent<TransformComp>().position;
        if (wallPos == pos) {
            std::cout << "Hit wall !" << std::endl;
            return true;
        }
    }
    return false;
}

void BombComp::checkPlayer(Vector3D pos)
{
    //for each players :
    for (const auto &player : entity->_mgr.getEntitiesInGroup(Players)) {
        auto &playerComp = player->getComponent<Player>();
        auto &playerPos = player->getComponent<TransformComp>().position;
        if (pos == playerComp.getNearestBlockPos(playerPos)) {
            std::cout << "Hit player !" << std::endl;
            //            playerComp.takeDamage();
        }
    }
}


