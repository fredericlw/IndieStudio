/*
** EPITECH PROJECT, 2024
** MovementComp.cpp
** File description:
** Created by Leo Fabre
*/
#include <raylib_encap/EKeyboardInputModule.hpp>
#include <raylib_encap/EGamepadInputModule.hpp>
#include "MovementComp.hpp"
#include "ECS/Entity.hpp"

MovementComp::MovementComp(EInputType input_type, PlayerNum num)
    : Velocity(Vector3D::Zero()), _speed(.5f)
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
    if (_inputMod->GetButtonDown(Right)) {
        std::cout << "RIGHT DOWN" << std::endl;
        Velocity.x = 1;
    } else if (_inputMod->GetButtonDown(Left)) {
        std::cout << "Left DOWN" << std::endl;
        Velocity.x = -1;
    } else {
        std::cout << "Left/right UP ?" << std::endl;
        Velocity.x = 0;
    }
    if (_inputMod->GetButtonDown(Up)) {
        std::cout << "Up DOWN" << std::endl;
        Velocity.y = 1;
    } else if (_inputMod->GetButtonDown(Down)) {
        std::cout << "Down DOWN" << std::endl;
        Velocity.y = -1;
    } else {
        std::cout << "Down UP ?" << std::endl;
        Velocity.y = 0;
    }


    transform->position += Velocity.Multiply(_speed);
    std::cout << "Velocity : " << Velocity << std::endl;
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
