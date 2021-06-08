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
}

void Manager::addBackToHowToPlayButton()
{
    auto size = Vector2D{350, 50};
    auto halfsize = Vector2D{size.x / 2, size.y / 2};
    auto winSize = Window::GetWinSize();
    auto pos = Vector2D{winSize.x - size.x, winSize.y - size.y};
    auto &BackToGameBtnEnt = addEntity("BackToGameButton");
    auto &textTest = addEntity("textTest");
    textTest.addComponent<TextComp>("ceci est un text", Green);
    textTest.addComponent<TransformComp>(200, 200 , 200);
    BackToGameBtnEnt.addComponent<TransformComp>(pos);
    BackToGameBtnEnt.addComponent<OptionComp>();
    BackToGameBtnEnt.addComponent<ButtonComp>("BACK TO GAME", size);
    BackToGameBtnEnt.getComponent<ButtonComp>().AddEventFunc(
            [this]() {
                setNextSceneToLoad(MainMenu);
                alive = false;
            }
    );
    BackToGameBtnEnt.addGroup(GUI);
    textTest.addGroup(GUI);
}