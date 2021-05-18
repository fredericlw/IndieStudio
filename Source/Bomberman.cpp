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

Bomberman::Bomberman(bool fullscreen)
    : mainWindow(std::make_unique<Window>(fullscreen)),
      alive(true),
      startTime(std::time(nullptr))
{
    GameLoop();
}

void Bomberman::GameLoop()
{
    auto& logoEnt = mgr.addEntity("MainMenuLogo");
    logoEnt.addComponent<PositionComponent>(0,0);
    logoEnt.addComponent<Sprite2D>("rsc/mainlogo.png");
    logoEnt.getComponent<PositionComponent>()
        .setPos(0,GetScreenHeight() - logoEnt.getComponent<Sprite2D>().getTex().height);


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
