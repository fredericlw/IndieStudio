/*
** EPITECH PROJECT, 2024
** MainMenuScene.cpp
** File description:
** Created by Leo Fabre
*/
#include <ECS/Manager.hpp>
#include <Components/3D/BasicCubeComp.hpp>
#include <raylib_encap/Math/Vector2D.hpp>
#include "Components/Components.h"

void Manager::loadMenuScene()
{
    AddMenuLogo();
    AddPlayButton();
    AddQuitButton();
}

void Manager::AddPlayButton()
{
    auto &PlayBtnEnt = addEntity("PlayButton");
    PlayBtnEnt.addComponent<TransformComp>(Vector2D::ScreenCenter());
    auto size = Vector2D{150, 50};
    auto halfsize = Vector2D{size.x / 2, size.y / 2};
    auto pos = Vector2D::ScreenCenter().Subtract(halfsize);
    PlayBtnEnt.addComponent<ButtonComp>("PLAY", size);
    PlayBtnEnt.getComponent<ButtonComp>().AddEventFunc(
        [this]() {
            setNextSceneToLoad(Lobby);
            alive = false;
        }
    );
}

void Manager::AddQuitButton()
{
    auto size = Vector2D{150, 50};
    auto halfsize = Vector2D{size.x / 2, size.y / 2};
    auto pos = Vector2D::ScreenCenter().Subtract(halfsize).Add({0, 70});
    auto &PlayBtnEnt = addEntity("QuitButton");
    PlayBtnEnt.addComponent<TransformComp>(pos);
    PlayBtnEnt.addComponent<ButtonComp>("QUIT", size);
    PlayBtnEnt.getComponent<ButtonComp>().AddEventFunc(
        [this]() {Quit();}
    );
}

void Manager::AddMenuLogo()
{
    //Create an entity
    auto &logoEntity = addEntity("MainMenuLogo");
    //Add Components to it
    logoEntity.addComponent<TransformComp>(0, 0);
    logoEntity.addComponent<Sprite2D>("rsc/mainlogo.png");
    //Modify some components
    int ypos = GetScreenHeight() -
        logoEntity.getComponent<Sprite2D>().height;
    logoEntity.getComponent<TransformComp>().position.y = (float) ypos;
}
