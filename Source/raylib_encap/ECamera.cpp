/*
** EPITECH PROJECT, 2024
** ECamera.cpp
** File description:
** Created by Leo Fabre
*/
#include "raylib_encap/ECamera.hpp"

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

Matrix ECamera::getMatrix()
{
    return GetCameraMatrix(*this);
}
