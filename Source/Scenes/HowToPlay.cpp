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
#include <GUI/ResizableTextComp.hpp>
#include "Components/Components.h"

void Manager::loadHowToPlayScene()
{
    addBackToHowToPlayButton();
    AddHowToPlayName();
    AddHowToPlayRules();
    addControlsHowToPlayButton();
}

void Manager::AddHowToPlayName() {
    auto &HowToPlayName = addEntity("HowToPlayName");
    HowToPlayName.addComponent<TransformComp>(Vector2D::ScreenCenter().x, 0);
    HowToPlayName.addComponent<TextComp>("How to Play?", Black);
    HowToPlayName.addGroup(GUI);
}

void Manager::AddHowToPlayRules() {
    auto &HowToPlayRules = addEntity("HowToPlayRules");
    HowToPlayRules.addComponent<TransformComp>(Vector2D::ScreenCenter().x, Vector2D::ScreenCenter().y - 195);
    HowToPlayRules.addComponent<ResizableTextComp>("Pressing a button will make the Bomberman drop a bomb at his feets.\n"
                                          "This bomb will pulse for a few seconds and then explode, shooting flames\n"
                                          "horizontally and vertically.\n\n"
                                          "The game revolves around the idea of using these bomb blasts to destroy\n"
                                          "walls and enemies.\n"
                                          "If the flame from any bomb hits any character it will injure or kill them.\n\n"
                                          "The goal of this game is to be the last alive.", DarkBlue, 30);
    HowToPlayRules.addGroup(GUI);
}

void Manager::addBackToHowToPlayButton()
{
    auto size = Vector2D{400, 50};
    auto winSize = Window::GetWinSize();
    auto pos = Vector2D{0, winSize.y - size.y};
    auto &BackToGameBtnEnt = addEntity("BackToGameButton");
    BackToGameBtnEnt.addComponent<TransformComp>(pos);
    BackToGameBtnEnt.addComponent<ButtonComp>("Back to main menu", size);
    BackToGameBtnEnt.getComponent<ButtonComp>().AddEventFunc(
            [this]() {
                setNextSceneToLoad(MainMenu);
                alive = false;
            }
    );
    BackToGameBtnEnt.addGroup(GUI);
}

void Manager::addControlsHowToPlayButton()
{
    auto size = Vector2D{300, 50};
    auto halfsize = Vector2D{size.x / 2, size.y / 2};
    auto winSize = Window::GetWinSize();
    auto pos = Vector2D{(winSize.x / 2) - halfsize.x, winSize.y - size.y};
    auto &BackToGameBtnEnt = addEntity("ControlsButton");
    BackToGameBtnEnt.addComponent<TransformComp>(pos);
    BackToGameBtnEnt.addComponent<ButtonComp>("Controls", size);
    BackToGameBtnEnt.getComponent<ButtonComp>().AddEventFunc(
        [this]() {
            setNextSceneToLoad(Controls);
            alive = false;
        }
    );
    BackToGameBtnEnt.addGroup(GUI);
}