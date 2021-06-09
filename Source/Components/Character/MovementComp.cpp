/*
** EPITECH PROJECT, 2024
** MovementComp.cpp
** File description:
** Created by Leo Fabre
*/
#include <raylib_encap/Input/EKeyboardInputModule.hpp>
#include <raylib_encap/Input/EGamepadInputModule.hpp>
#include <Logic/BombComp.hpp>
#include "Components/Character/MovementComp.hpp"
#include "ECS/Entity.hpp"
#include "raylib_encap/Math/CubeCollider.hpp"
#include "Manager.hpp"

MovementComp::MovementComp(EInputType input_type, PlayerNum num)
    : Velocity(Vector3D::Zero()),
      _speed(BASESPEED)
{
    GenerateInputModule(input_type, num);
}

MovementComp::~MovementComp()
{
    delete _inputMod;
}

void MovementComp::init()
{
    Component::init();
    transform = &entity->getComponent<TransformComp>();
    if (!transform)
        transform = &entity->addComponent<TransformComp>();
    feet_cube = &entity->getComponent<BasicCubeComp>();
    if (!feet_cube) {
        std::cerr << "CUBE WAS NOT FOUND" << std::endl;
        feet_cube =
            &entity->addComponent<BasicCubeComp>(Vector3D::One().Multiply(2));
    }
}

void MovementComp::update()
{
    Component::update();
    if (_inputMod->GetButtonDown(Right)) Velocity.x = 1;
    else if (_inputMod->GetButtonDown(Left)) Velocity.x = -1;
    else Velocity.x = 0;

    if (_inputMod->GetButtonDown(Up)) Velocity.z = -1;
    else if (_inputMod->GetButtonDown(Down)) Velocity.z = 1;
    else Velocity.z = 0;

    bool collides = false;
    Vector3D nextPos = transform->position;
    nextPos.Add(Velocity.Clamp(1).Multiply(_speed));
    for (auto &i : entity->_mgr.getEntitiesInGroup(GroupLabel::Walls)) {
        BasicCubeComp *cast = &i->getComponent<BasicCubeComp>();
        if (cast && CubeCollider::CheckBoxOverLap(
            feet_cube->getCube(), nextPos, cast->getCube())) {
            feet_cube->stickCube(nextPos, cast->getCube());
        }
    }
    for (auto &i : entity->_mgr.getEntitiesInGroup(GroupLabel::Obstacles)) {
        BasicCubeComp *cast = &i->getComponent<BasicCubeComp>();
        if (cast && CubeCollider::CheckBoxOverLap(
            feet_cube->getCube(), nextPos, cast->getCube())) {
            feet_cube->stickCube(nextPos, cast->getCube());
        }
    }
    //TODO : Fix player bumped around when dropping a bomb bc of this collision code
//    for (auto &i : entity->_mgr.getEntitiesInGroup(GroupLabel::Bombs)) {
//        BombComp *cast = &i->getComponent<BombComp>();
//        if (cast && CubeCollider::CheckBoxOverLap(
//            feet_cube->getCube(), nextPos, cast->getCube())) {
//            feet_cube->stickCube(nextPos, cast->getCube());
//        }
//    }
    transform->position = nextPos;
    if (Velocity != Vector3D::Zero()) {
        //        std::cout << "Player pos : " << transform->position << std::endl;
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
