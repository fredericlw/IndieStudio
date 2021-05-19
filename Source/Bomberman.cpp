/*
** EPITECH PROJECT, 2024
** Bomberman.cpp
** File description:
** Created by Leo Fabre
*/
#include <iostream>
//#include <unistd.h>
#include <Components/TransformComp.hpp>
#include <Components/Sprite2D.hpp>
#include <Components/BasicCubeComp.hpp>
#include "Bomberman.hpp"

Bomberman::Bomberman(bool fullscreen)
    : mainWindow(std::make_unique<Window>(fullscreen)),
      startTime(std::time(nullptr)),
      mgr(std::make_shared<Manager>())
{
    mgr->loadScene(Manager::MainMenu);
    GameLoop();
}

void Bomberman::GameLoop()
{
    while (mgr->isAlive()) {
        if (std::difftime(std::time(nullptr), startTime) > 5) mgr->Quit();
        mgr->update();
        mgr->draw();
    }
}

Bomberman::~Bomberman()
{
}