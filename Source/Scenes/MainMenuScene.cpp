/*
** EPITECH PROJECT, 2024
** MainMenuScene.cpp
** File description:
** Created by Leo Fabre
*/
#include <ECS/Manager.hpp>
#include <Components/3D/BasicCubeComp.hpp>
#include <raylib_encap/Math/Vector2D.hpp>
#include <GUI/AnimatedSprite.hpp>
#include <raylib_encap/Window.hpp>
#include "Components/Components.h"

void Manager::loadMenuScene()
{
    Entity *gl = getEntByName("gamelogic").get();
    if (!gl) {
        gl = &addEntity("gamelogic");
        gl->addComponent<AssetLoader>();
    }
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
    PlayBtnEnt.addGroup(GUI);
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
    PlayBtnEnt.addGroup(GUI);
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
            setNextSceneToLoad(HowToPlay);
            alive = false;
        }
    );
    PlayBtnEnt.addGroup(GUI);
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
    PlayBtnEnt.addGroup(GUI);
}

void Manager::AddMenuLogo()
{
    //Create an entity
    auto &logoEntity = addEntity("MainMenuLogo");
    //Add Components to it
    auto transformComp = logoEntity.addComponent<TransformComp>();
    auto spriteComp = logoEntity.addComponent<Sprite2D>("Assets/Textures/mainlogo.png");
    auto size = Vector2D{static_cast<float>(spriteComp.width), static_cast<float>(spriteComp.height)};
    Vector2D pos(Vector2D::ScreenCenter().Subtract(Vector2D(size.x / 2, size.y / 2)));
    transformComp.position = pos;

    //Modify some components
    logoEntity.addGroup(GUI);
}
