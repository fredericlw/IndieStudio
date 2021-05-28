/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by Frédéric LAWECKI--WALKOWIAK
*/

#include <Manager.hpp>
#include <raylib_encap/Math/Vector2D.hpp>
#include "Components/Components.h"

void Manager::loadLobbyScene() {
    AddMenuButton();
    AddGameButton();
}

void Manager::AddMenuButton() {
    auto &backMenu = addEntity("MenuButton");
    backMenu.addComponent<TransformComp>();
    auto size = Vector2D{400, 50};
    auto pos = Vector2D{0, 0};
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
    backMenu.addComponent<TransformComp>();
    auto size = Vector2D{300, 50};
    auto pos = Vector2D{500, 200};
    backMenu.addComponent<ButtonComp>("Start game", size, pos);
    backMenu.getComponent<ButtonComp>().AddEventFunc(
            [this]() {
                setNextSceneToLoad(Game);
                alive = false;
            }
    );
}