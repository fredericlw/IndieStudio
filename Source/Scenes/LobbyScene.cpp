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
    auto gl = getEntByName("gamelogic");
    gl->addComponent<LobbyComp>();
    AddMenuButton();
    AddGameButton();
    AddLobbyName();
}


void Manager::AddLobbyName() {
    auto &lobbyName = addEntity("LobbyName");
    lobbyName.addComponent<TransformComp>(Vector2D::ScreenCenter().x, 0);
    lobbyName.addComponent<TextComp>("Lobby", Black);
    lobbyName.addGroup(GUI);
}

void Manager::AddMenuButton() {
    auto &backMenu = addEntity("MenuButton");
    auto winSize = Window::GetWinSize();
    auto size = Vector2D{400, 50};
    auto pos = Vector2D{winSize.x / 2 - (winSize.x / 2), winSize.y - size.y};
    backMenu.addComponent<TransformComp>(pos);
    backMenu.addComponent<ButtonComp>("Back to main menu", size);
    backMenu.getComponent<ButtonComp>().AddEventFunc(
            [this]() {
                setNextSceneToLoad(MainMenu);
                curSceneAlive = false;
            }
    );
    backMenu.addGroup(GUI);

}

void Manager::AddGameButton() {
    auto &backMenu = addEntity("GameButton");
    auto winSize = Window::GetWinSize();
    auto size = Vector2D{300, 50};
    auto pos = Vector2D{winSize.x - size.x, winSize.y - size.y};
    backMenu.addComponent<TransformComp>(pos);
    backMenu.addComponent<ButtonComp>("Start game", size);
    backMenu.getComponent<ButtonComp>().AddEventFunc(
            [this]() {
                getEntByName(
                    "gamelogic")->getComponent<LobbyComp>().refreshSelections();
                setNextSceneToLoad(Game);
                curSceneAlive = false;
            }
    );
    backMenu.addGroup(GUI);
}