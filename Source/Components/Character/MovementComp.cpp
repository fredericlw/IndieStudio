/*
** EPITECH PROJECT, 2024
** MovementComp.cpp
** File description:
** Created by Leo Fabre
*/
#include <raylib_encap/Input/EKeyboardInputModule.hpp>
#include <raylib_encap/Input/EGamepadInputModule.hpp>
#include <Logic/BombComp.hpp>
#include <Logic/PowerUpComp.hpp>
#include <BaseValues.h>
#include "Components/Character/MovementComp.hpp"
#include "ECS/Entity.hpp"
#include "raylib_encap/Math/CubeCollider.hpp"
#include "Manager.hpp"
#include "EiaInputModule.hpp"

MovementComp::MovementComp(EInputType input_type, PlayerNum num)
    : Velocity(Vector3D::Zero()),
      LastVelocity(Vector3D::Zero()),
      _speed(BASESPEED),
      _active(true),
      input_type(input_type),
      num(num)
{
}

MovementComp::~MovementComp()
{
    delete _inputMod;
}

void MovementComp::init()
{
    Component::init();
    GenerateInputModule(input_type, num);
    transform = &entity->getComponent<TransformComp>();
    if (!transform)
        transform = &entity->addComponent<TransformComp>();
    collider = &entity->getComponent<BasicCubeComp>();
    if (!collider) {
        std::cerr << "CUBE WAS NOT FOUND, adding new..." << std::endl;
        collider =
            &entity->addComponent<BasicCubeComp>(Vector3D::One().Multiply(2));
    }
    _pmc =
        &entity->_mgr.getEntByName("gamelogic")->getComponent<PauseMenuComp>();
}

void MovementComp::update()
{
    if (!_active || _pmc->isPaused()) return;
    Component::update();
    if (_inputMod->GetButtonDown(Right)) Velocity.x = 1;
    else if (_inputMod->GetButtonDown(Left)) Velocity.x = -1;
    else Velocity.x = 0;

    //todo this is just a test
//    if (_inputMod->GetButtonPressed(Accept)) {
//        transform->position.y += 1;
//        std::cout << "pos Y " << transform->position.y <<std::endl;
//    }

    if (_inputMod->GetButtonDown(Up)) Velocity.z = -1;
    else if (_inputMod->GetButtonDown(Down)) Velocity.z = 1;
    else Velocity.z = 0;

    if (!(Velocity == LastVelocity))
        rotateTowardsDirection();

    LastVelocity = Velocity;

    Vector3D nextPos = transform->position;
    nextPos.Add(Velocity.Clamp(1).Multiply(_speed));

    for (auto &i : entity->_mgr.getEntitiesInGroup(GroupLabel::Walls)) {
        BasicCubeComp *cast = &i->getComponent<BasicCubeComp>();
        if (cast && CubeCollider::CheckBoxOverLap(
            collider->getCube(), nextPos, cast->getCube())) {
            collider->stickCube(nextPos, cast->getCube());
        }
    }

    if (entity->getComponent<PlayerComp>().getPowerUp() != SOFT_BLOCK_PASS) {
        for (auto &i : entity->_mgr.getEntitiesInGroup(GroupLabel::Obstacles)) {
            BasicCubeComp *cast = &i->getComponent<BasicCubeComp>();
            if (cast && CubeCollider::CheckBoxOverLap(
                collider->getCube(), nextPos, cast->getCube())) {
                collider->stickCube(nextPos, cast->getCube());
            }

        }
    }

    Vector3D theoNextPos = nextPos;
    for (auto &i : entity->_mgr.getEntitiesInGroup(GroupLabel::Bombs)) {
        BombComp *cast = &i->getComponent<BombComp>();
        collider->stickCube(theoNextPos, cast->getCube());
        if (CubeCollider::CheckBoxOverLap(
            collider->getCube(), transform->position, cast->getCube()) && theoNextPos != transform->position) {
//            std::cout << "bomb touch old pos" << std::endl;
        } else if (CubeCollider::CheckBoxOverLap(collider->getCube(), nextPos, cast->getCube())) {
//            std::cout << "already on cube" << std::endl;
            collider->stickCube(nextPos, cast->getCube());
        }
    }

    if (nextPos != transform->position) {
        entity->assets()->WalkingSound.playMusic(entity->assets()->Volume);
        entity->getComponent<FramesModel>().SetIdle(false);
    } else {
        entity->getComponent<FramesModel>().SetIdle(true);
    }
    for (const auto &item : entity->_mgr.getEntitiesInGroup(PowerUps)) {
        TransformComp *PUTransform = &item->getComponent<TransformComp>();
        if (PUTransform &&
            Vector3D::getNearestBlockPos(PUTransform->position) ==
                Vector3D::getNearestBlockPos(transform->position)) {
            auto &powerup = PUTransform->entity->getComponent<PowerUpComp>();
            auto &playerComp = entity->getComponent<PlayerComp>();
            playerComp.setPowerUp(powerup.type);
            powerup.entity->destroy();
        }
    }
    transform->position = nextPos;
}

void MovementComp::rotateTowardsDirection() const
{
    if (Velocity.x == 1) {
        entity->getComponent<FramesModel>().rotate({0, -1.5707963268 , 0});
    }
    if (Velocity.x == -1) {
        entity->getComponent<FramesModel>().rotate({0, 1.5707963268, 0});
    }
    if (Velocity.z == -1) {
        entity->getComponent<FramesModel>().rotate({0, 3.1415926536, 0});
    }
    if (Velocity.z== 1) {
        entity->getComponent<FramesModel>().rotate({0, 0, 0});
    }
}

void MovementComp::GenerateInputModule(EInputType type, PlayerNum num)
{
    switch (type) {
    case Keyboard:
        _inputMod = new EKeyboardInputModule(num);
        break;
    case Gamepad:
        _inputMod = new EGamepadInputModule(num);
        break;
    case AI:
        _inputMod = new EIAInputModule(num, entity->_mgr);
        break;
    }
}

float MovementComp::getSpeed() const
{
    return _speed;
}

void MovementComp::setSpeed(float speed)
{
    if (speed < 0)
        speed = 0;
    else if (speed > 10)
        speed = 10;
    _speed = speed;
}

AInputModule *MovementComp::getInputModule()
{
    return _inputMod;
}

void MovementComp::SetActive(bool state)
{
    _active = state;
}
