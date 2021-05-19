/*
** EPITECH PROJECT, 2024
** BasicCubeComp.cpp
** File description:
** Created by Leo Fabre
*/
#include <raylib.h>
#include "BasicCubeComp.hpp"
#include "ECS/Entity.hpp"
#include "TransformComp.hpp"
#include "ECS/Manager.hpp"

BasicCubeComp::BasicCubeComp()
{
}

BasicCubeComp::~BasicCubeComp()
{
}

void BasicCubeComp::init()
{
    Component::init();
}

void BasicCubeComp::update()
{
    Component::update();
}

void BasicCubeComp::draw()
{
    Component::draw();
//TODO: Must figure out where to keep that camera before anything 3D
//  Maybe manager should keep it and pass a ref to all entities
//  So then we would use &entity->mainCamera
////////////
    BeginMode3D(entity->_mgr->MainCam);
//
    DrawCube(entity->getComponent<TransformComp>().position, 2.0f, 2.0f, 2.0f, RED);
    DrawCubeWires(entity->getComponent<TransformComp>().position, 2.0f, 2.0f, 2.0f, WHITE);
//
//
    EndMode3D();
}
