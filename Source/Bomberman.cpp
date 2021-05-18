/*
** EPITECH PROJECT, 2024
** Bomberman.cpp
** File description:
** Created by Leo Fabre
*/
#include <iostream>
#include <unistd.h>
#include <Components/PositionComponent.hpp>
#include <Components/Sprite2D.hpp>
#include "Bomberman.hpp"
#include "Scenes/MainMenuScene.hpp"

Bomberman::Bomberman(bool fullscreen)
    : mainWindow(std::make_unique<Window>(fullscreen)),
      alive(true),
      startTime(std::time(nullptr))
{
    GameLoop();
}

void Bomberman::GameLoop()
{
    MainMenuScene scene;
    mgr.loadScene(scene);

    while (alive) {
        if (std::difftime(std::time(nullptr), startTime) > 5) Quit();
        mgr.update();
        mgr.draw();
    }
}

Bomberman::~Bomberman()
{
}

void Bomberman::Quit()
{
    alive = false;
}
