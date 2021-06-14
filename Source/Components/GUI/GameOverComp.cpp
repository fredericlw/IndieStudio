/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by Achille Bourgault
*/

#include <raylib_encap/Math/Vector2D.hpp>
#include <raylib_encap/Window.hpp>
#include <3D/TransformComp.hpp>
#include <GUI/ButtonComp.hpp>
#include <GUI/TextComp.hpp>
#include "Components/GUI/GameOverComp.hpp"
#include "Entity.hpp"
#include "Manager.hpp"

GameOverComp::GameOverComp(std::array<bool, 4> playerScores)
{
    _alive = playerScores;
}

void GameOverComp::init()
{
    Component::init();
    auto &text = entity->_mgr.addEntity("Game over");
    addTitle();
    addQuitBtn();
    DisplayScores();
}

void GameOverComp::addQuitBtn()
{
    auto size = Vector2D{350, 50};
    auto winCenter = Vector2D::ScreenCenter();
    auto pos = Vector2D{winCenter.x - (size.x/2), winCenter.y + 130};
    auto &BackToGameBtnEnt = entity->_mgr.addEntity("BackToGameButton");
    BackToGameBtnEnt.addComponent<TransformComp>(pos);
    GoButton = &BackToGameBtnEnt.addComponent<ButtonComp>("QUIT", size);
    BackToGameBtnEnt.getComponent<ButtonComp>().AddEventFunc(
        [this]() {entity->_mgr.Quit();}
    );
    BackToGameBtnEnt.addGroup(GUI);
    BackToGameBtnEnt.getComponent<ButtonComp>().setVisible(false);
}

void GameOverComp::update()
{
    Component::update();
}

void GameOverComp::draw()
{
    Component::draw();
}

void GameOverComp::addTitle()
{
    auto &title = entity->_mgr.addEntity("GOTitle");
    title.addGroup(GUI);
    title.addComponent<TransformComp>(Vector2D::ScreenCenter().Subtract({0,200}));
    GoText = &title.addComponent<TextComp>("GAME OVER", RayWhite, 120, false);
}

void GameOverComp::DoGameOver() {
    GoText->setVisible(true);
    GoButton->setVisible(true);
    GoPlayerWin->setVisible(true);
    GoWinner->setVisible(true);
}

void GameOverComp::DisplayScores() {
    std::string name;
    int nb = -1;
    for (int i = 0; _alive[i] < 4; i++) {
        if (_alive[i] == true) {
            nb++;
            if (i == 0) {
                name = "Player 1";
            } else if (i == 1) {
                name = "Player 2";
            } else if (i == 2) {
                name = "Player 3";
            } else if (i == 3) {
                name = "Player 4";
            }
        }
    }
    if (nb == -1)
        name = "You Lose";
    auto &Scores1 = entity->_mgr.addEntity("GOWinnerIs");
    Scores1.addGroup(GUI);
    Scores1.addComponent<TransformComp>(Vector2D::ScreenCenter().Subtract({0,100}));
    GoPlayerWin = &Scores1.addComponent<TextComp>("Winner is:", RayWhite, 84, false);
    auto &winner = entity->_mgr.addEntity("GOWinner");
    winner.addGroup(GUI);
    winner.addComponent<TransformComp>(Vector2D::ScreenCenter().Subtract({0,30}));
    GoWinner = &winner.addComponent<TextComp>(name, RayWhite, 84, false);
}
