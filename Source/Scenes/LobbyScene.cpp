/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by Frédéric LAWECKI--WALKOWIAK
*/

#include <Manager.hpp>
#include <raylib_encap/Math/Vector2D.hpp>
#include <raylib_encap/Window.hpp>
#include "Components/Components.h"

void Manager::loadLobbyScene() {
    AddMenuButton();
    AddGameButton();
    AddLobbyName();
}

void Manager::AddLobbyName() {
    auto &lobbyName = addEntity("LobbyName");
    lobbyName.addComponent<TransformComp>(Vector2D::ScreenCenter().x, 0);
    lobbyName.addComponent<TextComp>("Lobby", Black);
}

void Manager::AddMenuButton() {
    auto &backMenu = addEntity("MenuButton");
    auto winSize = Window::GetWinSize();
    backMenu.addComponent<TransformComp>(winSize);
    auto size = Vector2D{400, 50};
    auto pos = Vector2D{winSize.x / 2 - (winSize.x / 2), winSize.y - size.y};
    backMenu.addComponent<ButtonComp>("Back to main menu", size, pos);
    backMenu.getComponent<ButtonComp>().AddEventFunc(
            [this]() {
                setNextSceneToLoad(MainMenu);
                alive = false;
            }
    );
}

void Manager::AddGameButton() {
    auto &backMenu = addEntity("GameButton");
    auto winSize = Window::GetWinSize();
    backMenu.addComponent<TransformComp>(winSize);
    auto size = Vector2D{300, 50};
    auto pos = Vector2D{winSize.x - size.x, winSize.y - size.y};
    backMenu.addComponent<ButtonComp>("Start game", size, pos);
    backMenu.getComponent<ButtonComp>().AddEventFunc(
            [this]() {
                setNextSceneToLoad(Game);
                alive = false;
            }
    );
}