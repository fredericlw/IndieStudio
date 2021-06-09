/*
** EPITECH PROJECT, 2024
** PowerUpComp.cpp
** File description:
** Created by Leo Fabre
*/
#include <raylib_encap/Math/Random.hpp>
#include <AssetLoader.hpp>
#include "PowerUpComp.hpp"
#include "Entity.hpp"
#include "Manager.hpp"

PowerUpComp::PowerUpComp()
    : type(FIRE)
//    : type((PowerUpType)Random::Range(NONE+1, ENUM_END-1))
{
    std::cout << "POWERUP CTOR ========================================" << std::endl;

}

PowerUpComp::~PowerUpComp()
{
}

void PowerUpComp::init()
{
    Component::init();
    entity->addGroup(GroupLabel::PowerUps);
    collider = &entity->addComponent<BasicCubeComp>(Vector3D::One().Multiply(2));
    collider->shouldDraw = false;

    auto &assets = entity->_mgr.getEntByName(
        "gamelogic")->getComponent<AssetLoader>();

    switch (type) {
    case NONE:
    case ENUM_END:
        std::cerr << "POWERUP ERR : BAD POWERUP TYPE" << std::endl;
        break;
    case FIRE:
        model = &entity->addComponent<ModelComp>(assets.FireupModel);
        break;
    case SKATE:
        model = &entity->addComponent<ModelComp>(assets.SkateModel);
        break;
    case BOMB_UP:
        model = &entity->addComponent<ModelComp>(assets.BombupModel);
        break;
    case SOFT_BLOCK_PASS:
        model = &entity->addComponent<ModelComp>(assets.SoftBlockPassModel);
        break;
    }
    model->setOffset({0, 1, 1});
}

void PowerUpComp::draw()
{
    Component::draw();
}
