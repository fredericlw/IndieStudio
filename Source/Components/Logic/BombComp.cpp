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
#include <raylib_encap/Easing.hpp>
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
      _owner(owner),
      _baseParticleSize(2.f),
      _particleStartTime(0)
{
    _curParticleScale = _baseParticleSize;
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
    collider.setPos(_transform->position);
    collider.setSize(Vector3D::One().Multiply(2));
}

void BombComp::update()
{
    Component::update();
    auto timeAlive = std::difftime(std::time(nullptr), spawnTime);
    if (timeAlive > 3 && !hasExploded) {
        explode();
    }
    if (hasExploded && _curParticleScale > 0.f) {
        std::cout << "SHOULD FADE OUT" << std::endl;
//        _curParticleScale -= 0.001f;
        clock_t current_clock = clock() - _particleStartTime;
        float current_time = (float)current_clock / CLOCKS_PER_SEC;
        _curParticleScale =
                    Easing::LinearOut(current_time, _baseParticleSize, 0, .3f);
        std::cout << "cur scale "<< _curParticleScale << std::endl;
        for (auto& particle : particles) {
            particle->getComponent<BasicCubeComp>().SetSizeCentered(
                _curParticleScale);
        }
    }
    if (hasExploded && _curParticleScale <= 0.f && !particlesCleared) {
        std::cout << "clearing particles." << std::endl;
        particlesCleared = true;
        for (auto &item : particles) {
            item->destroy();
        }
        entity->destroy();
    }
}

void BombComp::draw()
{
    Component::draw();
}

void BombComp::explode()
{
    hasExploded = true;
    _owner->droppedBombs--;
    model->SetVisibility(false);
    std::cout << "BOOM !" << std::endl;
    _explosion_sound->playSound();
    GenerateParticles();
    _particleStartTime = clock();
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
    bool onObstacle = checkObstacle(pos);
    auto &particleEnt = entity->_mgr.addEntity("boom_particle");
    particleEnt.addComponent<TransformComp>(pos);
    auto &cube =
        particleEnt.addComponent<BasicCubeComp>(Vector3D::One().Multiply(2), onObstacle?Green:Red);
//    particleEnt.addComponent<AnimatedSprite>("./rsc/explosion.png", Vector2D{5, 5});
    particleEnt.addGroup(Particles);
    particles.emplace_back(&particleEnt);
    return onObstacle;
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
            playerComp.takeDamage();
        }
    }
}

const ECube &BombComp::getCube() const
{
    return collider;
}


