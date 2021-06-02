/*
** EPITECH PROJECT, 2024
** MovementComp.cpp
** File description:
** Created by Leo Fabre
*/
#include <raylib_encap/Input/EKeyboardInputModule.hpp>
#include <raylib_encap/Input/EGamepadInputModule.hpp>
#include "Components/Character/MovementComp.hpp"
#include "ECS/Entity.hpp"
#include "raylib_encap/Math/CubeCollider.hpp"
#include "Manager.hpp"


MovementComp::MovementComp(EInputType input_type, PlayerNum num)
    : Velocity(Vector3D::Zero()),
      _speed(.5f)
{
    GenerateInputModule(input_type, num);
}

MovementComp::~MovementComp()
{
}

void MovementComp::init()
{
    Component::init();
    transform = &entity->getComponent<TransformComp>();
    if (!transform)
        transform = &entity->addComponent<TransformComp>();
    cube = &entity->getComponent<BasicCubeComp>();
    if (!cube)
        cube = &entity->addComponent<BasicCubeComp>(Vector3D::One());
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
    //move collider cube to new p
    for (auto &i : entity->_mgr.getEntitiesInGroup(GroupLabel::Walls)) {
       BasicCubeComp *cast = &i->getComponent<BasicCubeComp>();
       if ( cast && CubeCollider::CheckBoxOverLap(
            cube->getCube(),
            transform->position.Add(Velocity.Clamp(1).Multiply(_speed)),
            cast->getCube())) {
           std::cerr << "Colision detected" << std::endl;
           return;
       }
    }
    //if cube collides, return

    transform->position += Velocity.Clamp(1).Multiply(_speed);
    if (Velocity != Vector3D::Zero()) {
        std::cout << "Player pos : " << transform->position << std::endl;
    }
}

void MovementComp::GenerateInputModule(EInputType type, PlayerNum num)
{
    switch (type) {
    case Keyboard:
        _inputMod = std::make_unique<EKeyboardInputModule>(num);
        break;
    case Gamepad:
        _inputMod = std::make_unique<EGamepadInputModule>(num);
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
