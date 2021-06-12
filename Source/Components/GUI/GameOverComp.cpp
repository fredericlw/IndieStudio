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

GameOverComp::GameOverComp()
{
}

void GameOverComp::init()
{
    Component::init();
    addTitle();
    addQuitBtn();
}

void GameOverComp::addQuitBtn()
{
    auto size = Vector2D{350, 50};
    auto winCenter = Vector2D::ScreenCenter();
    auto pos = Vector2D{winCenter.x - (size.x/2), winCenter.y + 50};
    auto &BackToGameBtnEnt = entity->_mgr.addEntity("BackToGameButton");
    BackToGameBtnEnt.addComponent<TransformComp>(pos);
    BackToGameBtnEnt.addComponent<ButtonComp>("QUIT", size);
    BackToGameBtnEnt.getComponent<ButtonComp>().AddEventFunc(
        [this]() {entity->_mgr.Quit();}
    );
    BackToGameBtnEnt.addGroup(GUI);
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
    title.addComponent<TransformComp>(Vector2D::ScreenCenter().Subtract({0,70}));
    title.addComponent<TextComp>("GAME OVER", RayWhite, 120);
}
