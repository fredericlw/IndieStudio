/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by Achille Bourgault
*/

#include "Components/GUI/GameOverComp.hpp"

GameOverComp::GameOverComp()
{

}

void GameOverComp::init()
{
    Component::init();
}

void GameOverComp::update()
{
    Component::update();
}

void GameOverComp::draw()
{
    Component::draw();
}

void GameOverComp::addBackGameOverSceneButton()
{
    auto size = Vector2D{350, 50};
    auto halfsize = Vector2D{size.x / 2, size.y / 2};
    auto winSize = Window::GetWinSize();
    auto pos = Vector2D{winSize.x - size.x, winSize.y - size.y};
    auto &BackToGameBtnEnt = addEntity("BackToGameButton");
    BackToGameBtnEnt.addComponent<TransformComp>(pos);
    BackToGameBtnEnt.addComponent<ButtonComp>("BACK TO GAME", size);
    BackToGameBtnEnt.getComponent<ButtonComp>().AddEventFunc(
            [this]() {
                setNextSceneToLoad(MainMenu);
                alive = false;
            }
    );
    BackToGameBtnEnt.addGroup(GUI);
}