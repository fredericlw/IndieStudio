/*
** EPITECH PROJECT, 2024
** Bomberman.cpp
** File description:
** Created by Leo Fabre
*/
#include <iostream>
#include <unistd.h>
#include <Components/PositionComponent.hpp>
#include "Bomberman.hpp"

Bomberman::Bomberman(bool fullscreen)
    : mainWindow(std::make_unique<Window>(fullscreen)),
      alive(true),
      startTime(std::time(nullptr))
{
    auto &testEntity(mgr.addEntity());
    testEntity.addComponent<PositionComponent>();
    GameLoop();
}

void Bomberman::GameLoop()
{
    while (alive) {
        if (std::difftime(std::time(nullptr), startTime) > 5) Quit();
        mgr.update();
    }
}

Bomberman::~Bomberman()
{
}

void Bomberman::Quit()
{
    alive = false;
}
