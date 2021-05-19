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
    AddPlayButton();
}

void Bomberman::AddPlayButton()
{
    auto &PlayBtnEnt = mgr->addEntity("PlayButton");
    PlayBtnEnt.addComponent<TransformComp>(Vector2D::ScreenCenter());
    auto size = Vector2D{150, 50};
    auto halfsize = Vector2D{size.x / 2, size.y / 2};
    std::cout << "halfsize : " << halfsize << std::endl;
    auto pos = Vector2D::ScreenCenter().Subtract(halfsize);
    std::cout << "pos = "<< pos << std::endl;
    PlayBtnEnt.addComponent<ButtonComp>("PLAY", size, pos);
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
    logoEntity.getComponent<TransformComp>().position.y = (float) ypos;
}
