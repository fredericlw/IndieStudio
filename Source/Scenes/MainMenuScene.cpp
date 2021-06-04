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
    addBackToGameBtn();
    AddSettingsButton();
    AddHowToPlayButton();
}

void Manager::AddPlayButton()
{
    auto &PlayBtnEnt = addEntity("PlayButton");
    auto size = Vector2D{270, 50};
    auto halfsize = Vector2D{size.x / 2, size.y / 2};
    auto pos = Vector2D::ScreenCenter().Subtract(halfsize);
    PlayBtnEnt.addComponent<TransformComp>(pos);
    PlayBtnEnt.addComponent<ButtonComp>("Play", size);
    PlayBtnEnt.getComponent<ButtonComp>().AddEventFunc(
        [this]() {
            setNextSceneToLoad(Lobby);
            alive = false;
        }
    );
}

void Manager::AddSettingsButton()
{
    auto &PlayBtnEnt = addEntity("SettingsButton");
    auto size = Vector2D{270, 50};
    auto halfsize = Vector2D{size.x / 2, size.y / 2};
    auto pos = Vector2D::ScreenCenter().Subtract(halfsize).Add({0, 140});
    PlayBtnEnt.addComponent<TransformComp>(pos);
    PlayBtnEnt.addComponent<ButtonComp>("Settings", size);
    PlayBtnEnt.getComponent<ButtonComp>().AddEventFunc(
        [this]() {
            setNextSceneToLoad(Settings);
            alive = false;
        }
    );
}

void Manager::AddHowToPlayButton()
{
    auto &PlayBtnEnt = addEntity("HowToPlayButton");
    auto size = Vector2D{270, 50};
    auto halfsize = Vector2D{size.x / 2, size.y / 2};
    auto pos = Vector2D::ScreenCenter().Subtract(halfsize).Add({0, 70});
    PlayBtnEnt.addComponent<TransformComp>(pos);
    PlayBtnEnt.addComponent<ButtonComp>("How to Play", size);
    PlayBtnEnt.getComponent<ButtonComp>().AddEventFunc(
        [this]() {
            setNextSceneToLoad(Settings);
            alive = false;
        }
    );
}

void Manager::addBackToGameBtn()
{
    auto size = Vector2D{270, 50};
    auto halfsize = Vector2D{size.x / 2, size.y / 2};
    auto pos = Vector2D::ScreenCenter().Subtract(halfsize).Add({0, 210});
    auto &PlayBtnEnt = addEntity("QuitButton");
    PlayBtnEnt.addComponent<TransformComp>(pos);
    PlayBtnEnt.addComponent<ButtonComp>("Quit", size);
    PlayBtnEnt.getComponent<ButtonComp>().AddEventFunc(
        [this]() {Quit();}
    );
}

void Manager::AddMenuLogo()
{
    //Create an entity
    auto &logoEntity = addEntity("MainMenuLogo");
    //Add Components to it
    logoEntity.addComponent<TransformComp>(50, 0);
    logoEntity.addComponent<Sprite2D>("rsc/mainlogo.png");
    //Modify some components
    int ypos = GetScreenHeight() -
        logoEntity.getComponent<Sprite2D>().height - 430;
    logoEntity.getComponent<TransformComp>().position.y = (float) ypos;
}
