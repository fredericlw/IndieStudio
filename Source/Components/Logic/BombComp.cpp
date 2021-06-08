/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by Achille Bourgault
*/

#include <Component.hpp>
#include <GUI/AnimatedSprite.hpp>
#include <Logic/MapComponent.hpp>
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
            std::cout << "destroyed particle" << std::endl;
        }
        std::cout << "destroyed bomb" << std::endl;
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
    GenerateParticles();
    _explosion_sound->playSound();
}

void BombComp::GenerateParticles()
{
    //TODO : this is bad code pls fix
    Vector3D pos(_transform->position);

    SpawnParticle(pos);

    //right
    for (int i = 0; i < 3; i++) {
        pos.x += 2;
        SpawnParticle(pos);
        //check for barier
            //if explosion break
    }
    pos.x = _transform->position.x;

    for (int i = 0; i < 3; i++) {
        pos.x -= 2;
        SpawnParticle(pos);
        //check for barier
        //if explosion breaka
    }
    pos.x = _transform->position.x;

    for (int i = 0; i < 3; i++) {
        pos.z -= 2;
        SpawnParticle(pos);
        //check for barier
        //if explosion breaka
    }
    pos.z = _transform->position.z;

    /*auto mapPos = entity->_mgr.getEntByName("mapRoot")->getComponent<TransformComp>().position;
    ECube flameCube(pos, Vector3D::One());
    ECube wallCube(pos, Vector3D::One().Multiply(2));
    Vector3D wallCubePos({0,0,0});
    auto walls = entity->_mgr.getEntByName("mapRoot")->getComponent<MapComponent>().getWalls();
    auto obstacles = entity->_mgr.getEntByName("mapRoot")->getComponent<MapComponent>().getObstacles();
    for (int i = 0; i < 3; i++) {
        pos.z += 2;
        flameCube.setPos(pos);
        if (checkCol(mapPos, flameCube, wallCube, wallCubePos, obstacles)) {


            break;
        }
        if (checkCol(mapPos, flameCube, wallCube, wallCubePos, walls)) break;
        SpawnParticle(pos);
    }*/
}

bool BombComp::checkCol(
    const Vector3D &mapPos, const ECube &flameCube, ECube &wallCube,
    Vector3D &wallCubePos, std::vector<Vector2D> &walls
) const
{
    for (const auto& wall : walls) {
            wallCubePos = {(wall.x * 2) + mapPos.x, mapPos.y, (wall.y * 2) + mapPos.z};
            wallCube.setPos(wallCubePos);
        if (CubeCollider::CheckBoxOverLap(flameCube, wallCube)) {
            return true;
        }
    }
    return false;
}

void BombComp::SpawnParticle(Vector3D &pos)
{
    auto &testBoom = entity->_mgr.addEntity("boom");
    testBoom.addComponent<TransformComp>(pos);
    testBoom.addComponent<BasicCubeComp>(Vector3D::One().Multiply(2));
    testBoom.addGroup(Particles);
    particles.emplace_back(&testBoom);
}

