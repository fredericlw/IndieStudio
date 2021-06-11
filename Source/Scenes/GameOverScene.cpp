/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by daniyel gouasmi
*/

#include "Manager.hpp"
#include <ECS/Manager.hpp>
#include <Components/3D/BasicCubeComp.hpp>
#include <raylib_encap/Math/Vector2D.hpp>
#include <raylib_encap/Window.hpp>
#include "Components/Components.h"
#include "Components/GUI/OptionComp.hpp"

void Manager::loadGameOverScene() {
    std::cout << "Game Over" << std::endl;
    QuitGameOverSceneButton();

    //TODO : use PLAYER SCORE THEN DESTROY
}

void Manager::QuitGameOverSceneButton()
{
    auto size = Vector2D{350, 50};
    auto halfsize = Vector2D{size.x / 2, size.y / 2};
    auto winSize = Window::GetWinSize();
    auto pos = Vector2D{winSize.x - size.x, winSize.y - size.y};
    auto &BackToGameBtnEnt = addEntity("BackToGameButton");
    BackToGameBtnEnt.addComponent<TransformComp>(pos);
    BackToGameBtnEnt.addComponent<ButtonComp>("QUIT", size);
    BackToGameBtnEnt.getComponent<ButtonComp>().AddEventFunc(
            [this]() {Quit();}
    );
    BackToGameBtnEnt.addGroup(GUI);
}