/*
** EPITECH PROJECT, 2024
** ETime.cpp
** File description:
** Created by Leo Fabre
*/
#include "ETime.hpp"
#include "raylib.h"
ETime::ETime()
{
}

ETime::~ETime()
{
}

float ETime::DeltaTime()
{
    return GetFrameTime();
}
