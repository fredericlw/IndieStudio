/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by Achille Bourgault
*/


#include <ECS/Manager.hpp>
#include <Components/3D/BasicCubeComp.hpp>
#include <raylib_encap/Math/Vector2D.hpp>
#include <raylib_encap/Window.hpp>
#include "Components/Components.h"
#include "Components/GUI/OptionComp.hpp"

void Manager::loadHowToPlayScene()
{
    addBackToHowToPlayButton();
    AddHowToPlayName();
    AddHowToPlayRules();
}

void Manager::AddHowToPlayName() {
    auto &HowToPlayName = addEntity("HowToPlayName");
    HowToPlayName.addComponent<TransformComp>(Vector2D::ScreenCenter().x, 0);
    HowToPlayName.addComponent<TextComp>("How to Play?", Black);
    HowToPlayName.addGroup(GUI);
}

void Manager::AddHowToPlayRules() {
    auto &HowToPlayRules = addEntity("HowToPlayRules");
    HowToPlayRules.addComponent<TransformComp>(Vector2D::ScreenCenter().x, Vector2D::ScreenCenter().y);
    HowToPlayRules.addComponent<TextComp>("The rules of this game is to be the last alive", Black);
    HowToPlayRules.addGroup(GUI);
}

void Manager::addBackToHowToPlayButton()
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