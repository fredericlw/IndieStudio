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
#include "raylib_encap/Window.hpp"

class Bomberman {
public:
    explicit Bomberman(bool fullscreen);
    ~Bomberman();
private:
    std::shared_ptr<Window> mainWindow;
    std::time_t startTime;
    std::shared_ptr<Manager> mgr;
    void SceneLoop();
};

#endif //BOMBERMAN_HPP