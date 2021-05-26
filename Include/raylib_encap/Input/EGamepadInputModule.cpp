/*
** EPITECH PROJECT, 2024
** EGamepadInputModule.cpp
** File description:
** Created by Leo Fabre
*/
#include <raylib.h>
#include "EGamepadInputModule.hpp"

EGamepadInputModule::EGamepadInputModule(int gamepad_nbr)
    : _gamepadNbr(gamepad_nbr)
{
    KeyMap[Button::Accept] = GAMEPAD_BUTTON_RIGHT_FACE_DOWN;
    KeyMap[Button::Cancel] = GAMEPAD_BUTTON_RIGHT_FACE_RIGHT;
    KeyMap[Button::DropBomb] = GAMEPAD_BUTTON_RIGHT_TRIGGER_2;
}

EGamepadInputModule::~EGamepadInputModule()
{
}

bool EGamepadInputModule::GetButtonDown(Button btn)
{
    switch (btn) {
    case Left:
        return (GetGamepadAxisMovement(_gamepadNbr, GAMEPAD_AXIS_LEFT_X) > 0
        || IsGamepadButtonDown(_gamepadNbr, GAMEPAD_BUTTON_LEFT_FACE_LEFT));
    case Right:
        return (GetGamepadAxisMovement(_gamepadNbr, GAMEPAD_AXIS_LEFT_X) < 0
            || IsGamepadButtonDown(_gamepadNbr, GAMEPAD_BUTTON_LEFT_FACE_RIGHT));
    case Up:
        return (GetGamepadAxisMovement(_gamepadNbr, GAMEPAD_AXIS_LEFT_Y) > 0
            || IsGamepadButtonDown(_gamepadNbr, GAMEPAD_BUTTON_LEFT_FACE_UP));
    case Down:
        return (GetGamepadAxisMovement(_gamepadNbr, GAMEPAD_AXIS_LEFT_Y) < 0
            || IsGamepadButtonDown(_gamepadNbr, GAMEPAD_BUTTON_LEFT_FACE_DOWN));
    default:
        return IsGamepadButtonDown(_gamepadNbr, KeyMap[btn]);
    }
}

bool EGamepadInputModule::GetButtonUp(Button btn)
{
    switch (btn) {
    case Left:
        return (GetGamepadAxisMovement(_gamepadNbr, GAMEPAD_AXIS_LEFT_X) < 0
        || IsGamepadButtonUp(_gamepadNbr, GAMEPAD_BUTTON_LEFT_FACE_LEFT));
    case Right:
        return (GetGamepadAxisMovement(_gamepadNbr, GAMEPAD_AXIS_LEFT_X) > 0
            || IsGamepadButtonUp(_gamepadNbr, GAMEPAD_BUTTON_LEFT_FACE_RIGHT));
    case Up:
        return (GetGamepadAxisMovement(_gamepadNbr, GAMEPAD_AXIS_LEFT_Y) < 0
            || IsGamepadButtonUp(_gamepadNbr, GAMEPAD_BUTTON_LEFT_FACE_UP));
    case Down:
        return (GetGamepadAxisMovement(_gamepadNbr, GAMEPAD_AXIS_LEFT_Y) > 0
            || IsGamepadButtonUp(_gamepadNbr, GAMEPAD_BUTTON_LEFT_FACE_DOWN));
    default:
        return IsGamepadButtonUp(_gamepadNbr, KeyMap[btn]);
    }
}

//Will not return analog sticks info
bool EGamepadInputModule::GetButtonPressed(Button btn)
{
    switch (btn) {
    case Left:
        return (IsGamepadButtonPressed(_gamepadNbr, GAMEPAD_BUTTON_LEFT_FACE_LEFT));
    case Right:
        return (IsGamepadButtonPressed(_gamepadNbr, GAMEPAD_BUTTON_LEFT_FACE_RIGHT));
    case Up:
        return (IsGamepadButtonPressed(_gamepadNbr, GAMEPAD_BUTTON_LEFT_FACE_UP));
    case Down:
        return (IsGamepadButtonPressed(_gamepadNbr, GAMEPAD_BUTTON_LEFT_FACE_DOWN));
    default:
        return IsGamepadButtonPressed(_gamepadNbr, KeyMap[btn]);
    }
}

bool EGamepadInputModule::GetButtonReleased(Button btn)
{
    switch (btn) {
    case Left:
        return (IsGamepadButtonReleased(_gamepadNbr, GAMEPAD_BUTTON_LEFT_FACE_LEFT));
    case Right:
        return (IsGamepadButtonReleased(_gamepadNbr, GAMEPAD_BUTTON_LEFT_FACE_RIGHT));
    case Up:
        return (IsGamepadButtonReleased(_gamepadNbr, GAMEPAD_BUTTON_LEFT_FACE_UP));
    case Down:
        return (IsGamepadButtonReleased(_gamepadNbr, GAMEPAD_BUTTON_LEFT_FACE_DOWN));
    default:
        return IsGamepadButtonReleased(_gamepadNbr, KeyMap[btn]);
    }
}
