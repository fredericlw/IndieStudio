/*
** EPITECH PROJECT, 2024
** Bomberman.cpp
** File description:
** Created by Leo Fabre
*/
#include <iostream>
//#include <unistd.h>
#include <Components/3D/TransformComp.hpp>
#include <Components/GUI/Sprite2D.hpp>
#include <Components/3D/BasicCubeComp.hpp>
#include "Bomberman.hpp"

Bomberman::Bomberman(bool fullscreen)
    : mainWindow(std::make_unique<Window>(fullscreen)),
      startTime(std::time(nullptr)),
      mgr(std::make_shared<Manager>())
{
    mgr->loadScene(Manager::Game); //todo : fix scene changing segfault
    GameLoop();
}

void Bomberman::GameLoop()
{
    while (mgr->isAlive() && !mainWindow->ShouldClose()) {
//        if (std::difftime(std::time(nullptr), startTime) > 5) mgr->Quit();
        mgr->update();
        mgr->draw();
    }
    std::cerr << "GAMELOOP END" << std::endl;
}

Bomberman::~Bomberman()
{
}