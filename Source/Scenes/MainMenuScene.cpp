/*
** EPITECH PROJECT, 2024
** MainMenuScene.cpp
** File description:
** Created by Leo Fabre
*/
#include "MainMenuScene.hpp"
#include "Components/Components.h"

MainMenuScene::MainMenuScene()
    : Scene()
{
    AddLogo();
}

void MainMenuScene::AddLogo()
{
    //Create an entity
    std::shared_ptr<Entity> logoEntity = std::make_shared<Entity>("MainMenuLogo");
    //Add Components to it
    logoEntity->addComponent<TransformComp>(0, 0);
    logoEntity->addComponent<Sprite2D>("rsc/mainlogo.png");
    //Modify some components
    int ypos =
        GetScreenHeight() - logoEntity->getComponent<Sprite2D>().getTex().height;
    logoEntity->getComponent<TransformComp>().position.y = ypos;
    //Once done, put entity into scene hierarchy.
    entities.emplace_back(std::move(logoEntity));
}

void MainMenuScene::AddPlayBtn()
{
    auto playBtnEntity = std::make_shared<Entity>("PlayBtn");
//    playBtnEntity->addComponent<ButtonComp>("rsc/playBtn.png", )
}
