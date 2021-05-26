/*
** EPITECH PROJECT, 2024
** EMouseInputModule.cpp
** File description:
** Created by Leo Fabre
*/
#include "EMouseInputModule.hpp"
#include <raylib.h>

EMouseInputModule::EMouseInputModule()
{
}

EMouseInputModule::~EMouseInputModule()
{
}

bool EMouseInputModule::GetButtonDown(EMouseButton btn)
{
    return IsMouseButtonDown(
        btn == LeftClick ? MOUSE_BUTTON_LEFT : MOUSE_BUTTON_RIGHT
        );
}

bool EMouseInputModule::GetButtonUp(EMouseButton btn)
{
    return IsMouseButtonUp(
        btn == LeftClick ? MOUSE_BUTTON_LEFT : MOUSE_BUTTON_RIGHT
    );
}

bool EMouseInputModule::GetButtonPressed(EMouseButton btn)
{
    return IsMouseButtonPressed(
        btn == LeftClick ? MOUSE_BUTTON_LEFT : MOUSE_BUTTON_RIGHT
    );
}

bool EMouseInputModule::GetButtonReleased(EMouseButton btn)
{
    return IsMouseButtonReleased(
        btn == LeftClick ? MOUSE_BUTTON_LEFT : MOUSE_BUTTON_RIGHT
    );
}

Vector2D EMouseInputModule::GetMousePos()
{
    return GetMousePosition();
}
