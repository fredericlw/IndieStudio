/*
** EPITECH PROJECT, 2024
** PowerUpComp.cpp
** File description:
** Created by Leo Fabre
*/
#include <raylib_encap/Math/Random.hpp>
#include <AssetLoader.hpp>
#include <raylib_encap/Easing.hpp>
#include "Components/Logic/PowerUpComp.hpp"
#include "Entity.hpp"
#include "Manager.hpp"

PowerUpComp::PowerUpComp()
//    : type(FIREUP)
    : type((PowerUpType)Random::Range(NONE+1, ENUM_END-1))
{
    std::cout << "POWERUP CTOR ========================================" << std::endl;
    std::cout << "Type : " << type << std::endl;
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

    switch (type) {
    case NONE:
    case ENUM_END:
        std::cerr << "POWERUP ERR : BAD POWERUP TYPE" << std::endl;
        break;
    case FIREUP:
        model = &entity->addComponent<ModelComp>(entity->assets()->FireUpModel);
        break;
    case SKATE:
        model = &entity->addComponent<ModelComp>(entity->assets()->SkateModel);
        break;
    case BOMB_UP:
        model = &entity->addComponent<ModelComp>(entity->assets()->BombupModel);
        break;
    case SOFT_BLOCK_PASS:
        model = &entity->addComponent<ModelComp>(entity->assets()->SoftBlockPassModel);
        break;
    case FULLFIRE:
        model = &entity->addComponent<ModelComp>(entity->assets()->FullFireModel);
    }
    model->setOffset({0, 1, 1});
}

void PowerUpComp::update()
{
    Component::update();
    //Ease floating mid-air model offset.y
    Vector3D offset = model->getOffset();
    clock_t curClock = clock() - _startTime;
    float curTime = (float) curClock / CLOCKS_PER_SEC;
    float loopDuration = .3f;
    offset.y = Easing::SineInOut(curTime, 1, 0, loopDuration);
    model->setOffset(offset);
}

void PowerUpComp::draw()
{
    Component::draw();
}
