/*
** EPITECH PROJECT, 2024
** Bomberman.cpp
** File description:
** Created by Leo Fabre
*/
#include <iostream>
#include <memory>
#include "raylib_encap/Window.hpp"
//#include <unistd.h>
#include <Components/3D/TransformComp.hpp>
#include <Components/GUI/Sprite2D.hpp>
#include <Components/3D/BasicCubeComp.hpp>
#include "Bomberman.hpp"
#include <raylib_encap/EAudio.hpp>
#include "boost/filesystem.hpp"
#include "Manager.hpp"

Bomberman::Bomberman(bool fullscreen)
    : mainWindow(std::make_shared<Window>(fullscreen)),
      startTime(std::time(nullptr)),
      mgr(std::make_shared<Manager>(mainWindow))
{
    if (!boost::filesystem::exists(
        boost::filesystem::path("./Assets/Models/steve/walk/1.glb"))
        ) {
        std::cerr << std::endl << "FATAL ERROR : Assets not found. "
            << std::endl
            << "Make sure to run from app root folder." << std::endl;
        std::exit(84);
    }
    mgr->loadScene(Manager::MainMenu);
    mgr->SceneLoop();
}

Bomberman::~Bomberman()
{
}