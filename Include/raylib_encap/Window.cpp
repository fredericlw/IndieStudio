/*
** EPITECH PROJECT, 2024
** Window.cpp
** File description:
** Created by Leo Fabre
*/
#include "Window.hpp"

Window::Window(bool fullscreen)
    : screenSize(
    std::make_tuple(GetScreenWidth(), GetScreenHeight()))
{
    SetTargetFPS(60);
    if (fullscreen) {
        InitWindow(get<0>(screenSize), get<1>(screenSize), "Bomberman");
        ToggleFullscreen();
    } else {
        InitWindow(1280, 720, "Bomberman");
    }
}

Window::~Window()
{
    CloseWindow();
}

bool Window::ShouldClose()
{
    return WindowShouldClose();
}
