/*
** EPITECH PROJECT, 2024
** ECamera.cpp
** File description:
** Created by Leo Fabre
*/
#include "ECamera.hpp"

ECamera::ECamera() : Camera3D()
{
}

ECamera::~ECamera()
{
}

void ECamera::Begin3D()
{
    BeginMode3D(*this);
}

void ECamera::End3D()
{
    EndMode3D();
}
