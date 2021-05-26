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
    : Velocity(Vector3D::Zero())
{
    transform = &entity->getComponent<TransformComp>();
    if (!transform)
        transform = &entity->addComponent<TransformComp>();
    GenerateInputModule(input_type, num);
}

MovementComp::~MovementComp()
{
}

void MovementComp::update()
{
    Component::update();
    if (_inputMod->GetButtonDown(Right)) {
        Velocity.x = 1;
    } else if (_inputMod->GetButtonDown(Left)) {
        Velocity.x = -1;
    }
    if (_inputMod->GetButtonDown(Up)) {
        Velocity.y = 1;
    } else if (_inputMod->GetButtonDown(Down)) {
        Velocity.y = -1;
    }
    if (_inputMod->GetButtonUp(Right)) {
        Velocity.x = 0;
    } else if (_inputMod->GetButtonUp(Left)) {
        Velocity.x = 0;
    }
    if (_inputMod->GetButtonUp(Up)) {
        Velocity.y = 0;
    } else if (_inputMod->GetButtonUp(Down)) {
        Velocity.y = 0;
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
