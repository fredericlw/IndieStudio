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
{
    transform = &entity->getComponent<TransformComp>();
    if (!transform)
        transform = &entity->addComponent<TransformComp>();
    GenerateInputModule(input_type, num);
}

MovementComp::~MovementComp()
{
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
    }
}
