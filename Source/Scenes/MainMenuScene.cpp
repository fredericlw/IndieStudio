/*
** EPITECH PROJECT, 2024
** MainMenuScene.cpp
** File description:
** Created by Leo Fabre
*/
#include <ECS/Manager.hpp>
#include <Bomberman.hpp>
#include "Components/Components.h"

void Bomberman::LoadMenuScene()
{
    mgr->destroyOnLoad();
    AddMenuLogo();
}

void Bomberman::AddMenuLogo()
{
    //Create an entity
    auto &logoEntity = mgr->addEntity("MainMenuLogo");
    //Add Components to it
    logoEntity.addComponent<TransformComp>(0, 0);
    logoEntity.addComponent<Sprite2D>("rsc/mainlogo.png");
    //Modify some components
    int ypos =
        GetScreenHeight() -
            logoEntity.getComponent<Sprite2D>().getTex().height;
    logoEntity.getComponent<TransformComp>().position.y = (float)ypos;
}
