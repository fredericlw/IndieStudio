/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include <ECS/Manager.hpp>
#include <raylib_encap/Window.hpp>
#include <Entity.hpp>
#include <3D/TransformComp.hpp>
#include <GUI/ButtonComp.hpp>
#include <GUI/ResizableTextComp.hpp>
#include <GUI/TextComp.hpp>

void Manager::loadControlsScene()
{
    addBackToHowToPlayButton();
    addControlsRulesButton();
    addControlsSceneTitle();
    addFirstPlayerControls();
    addSecondPlayerControls();
    addThirdPlayerControls();
    addFourthPlayerControls();
    addPowerUpsButton();
}

void Manager::addFirstPlayerControls()
{
    auto &FirstPlayerControls = addEntity("FirstPlayerControls");
    FirstPlayerControls.addComponent<TransformComp>((Vector2D::ScreenCenter().x * 2) / 4 * 0.5, Vector2D::ScreenCenter().y - 150);
    FirstPlayerControls.addComponent<ResizableTextComp>("        Player 1:\nUP: Up arrow\nDOWN: Down arrow\nLEFT: Left arrow\nRIGHT: Right arrow\nDROP: Space\nPAUSE: Escape", DarkBlue, 30);
    FirstPlayerControls.addGroup(GUI);
}

void Manager::addSecondPlayerControls()
{
    auto &addSecondPlayerControls = addEntity("addSecondPlayerControls");
    addSecondPlayerControls.addComponent<TransformComp>((Vector2D::ScreenCenter().x * 2) / 4 * 1.5, Vector2D::ScreenCenter().y - 150);
    addSecondPlayerControls.addComponent<ResizableTextComp>("        Player 2:\nUP: Z\nDOWN: S\nLEFT: Q\nRIGHT: D\nDROP: E\nPAUSE: W", DarkBlue, 30);
    addSecondPlayerControls.addGroup(GUI);
}

void Manager::addThirdPlayerControls()
{
    auto &addThirdPlayerControls = addEntity("addThirdPlayerControls");
    addThirdPlayerControls.addComponent<TransformComp>((Vector2D::ScreenCenter().x * 2) / 4 * 2.5, Vector2D::ScreenCenter().y - 150);
    addThirdPlayerControls.addComponent<ResizableTextComp>("        Player 3:\nUP: T\nDOWN: G\nLEFT: F\nRIGHT: H\nDROP: Y\nPAUSE: V", DarkBlue, 30);
    addThirdPlayerControls.addGroup(GUI);
}

void Manager::addFourthPlayerControls()
{
    auto &addFourthPlayerControls = addEntity("addFourthPlayerControls");
    addFourthPlayerControls.addComponent<TransformComp>((Vector2D::ScreenCenter().x * 2) / 4 * 3.5, Vector2D::ScreenCenter().y - 150);
    addFourthPlayerControls.addComponent<ResizableTextComp>("        Player 4:\nUP: I\nDOWN: K\nLEFT: J\nRIGHT: L\nDROP: O\nPAUSE: Semicolon", DarkBlue, 30);
    addFourthPlayerControls.addGroup(GUI);
}


void Manager::addControlsSceneTitle()
{
    auto &HowToPlayName = addEntity("ControlSceneTitle");
    HowToPlayName.addComponent<TransformComp>(Vector2D::ScreenCenter().x, 0);
    HowToPlayName.addComponent<TextComp>("Controls", Black);
    HowToPlayName.addGroup(GUI);
}

void Manager::addControlsRulesButton()
{
    auto size = Vector2D{300, 50};
    auto halfsize = Vector2D{size.x / 2, size.y / 2};
    auto winSize = Window::GetWinSize();
    auto pos = Vector2D{(winSize.x / 2) - halfsize.x, winSize.y - size.y};
    auto &BackToGameBtnEnt = addEntity("RulesButton");
    BackToGameBtnEnt.addComponent<TransformComp>(pos);
    BackToGameBtnEnt.addComponent<ButtonComp>("How to play", size);
    BackToGameBtnEnt.getComponent<ButtonComp>().AddEventFunc(
        [this]() {
            setNextSceneToLoad(HowToPlay);
            curSceneAlive = false;
        }
    );
    BackToGameBtnEnt.addGroup(GUI);
}
