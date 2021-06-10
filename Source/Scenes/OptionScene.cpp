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

void Manager::loadOptionScene()
{
    std::cout << getEntByName("gamelogic") << std::endl;
    addBackToGameOptionBtn();
    AddOptionName();
}

void Manager::AddOptionName() {
    auto &OptionName = addEntity("SettingsName");
    OptionName.addComponent<TransformComp>(Vector2D::ScreenCenter().x, 0);
    OptionName.addComponent<TextComp>("Settings", Black);
    OptionName.addGroup(GUI);

    std::cout << OptionName.assets()->Volume << std::endl;
}

void Manager::addBackToGameOptionBtn()
{
    auto size = Vector2D{350, 50};
    auto halfsize = Vector2D{size.x / 2, size.y / 2};
    auto winSize = Window::GetWinSize();
    auto pos = Vector2D{winSize.x - size.x, winSize.y - size.y};
    auto &BackToGameBtnEnt = addEntity("BackToGameButton");
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
}
