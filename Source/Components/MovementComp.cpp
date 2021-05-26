/*
** EPITECH PROJECT, 2024
** MovementComp.cpp
** File description:
** Created by Leo Fabre
*/
#include <raylib_encap/Input/EKeyboardInputModule.hpp>
#include <raylib_encap/Input/EGamepadInputModule.hpp>
#include "Components/MovementComp.hpp"
#include "ECS/Entity.hpp"

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
}

void MovementComp::update()
{
    Component::update();
    if (_inputMod->GetButtonDown(Right)) Velocity.x = 1;
    else if (_inputMod->GetButtonDown(Left)) Velocity.x = -1;
    else Velocity.x = 0;

    if (_inputMod->GetButtonDown(Up)) Velocity.y = 1;
    else if (_inputMod->GetButtonDown(Down)) Velocity.y = -1;
    else Velocity.y = 0;

    transform->position += Velocity.Multiply(_speed).Clamp(1);
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
