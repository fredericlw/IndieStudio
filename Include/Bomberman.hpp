/*
** EPITECH PROJECT, 2024
** Bomberman.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef BOMBERMAN_HPP
#define BOMBERMAN_HPP

#include <memory>
#include <ECS/Manager.hpp>
#include <ctime>
#include "raylib/Window.hpp"

class Bomberman {
public:
    explicit Bomberman(bool fullscreen);
    ~Bomberman();
private:
    std::unique_ptr<Window> mainWindow;
    std::time_t startTime;
    std::shared_ptr<Manager> mgr;
    void GameLoop();
};

#endif //BOMBERMAN_HPP