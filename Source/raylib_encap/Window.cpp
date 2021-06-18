/*
** EPITECH PROJECT, 2024
** Window.cpp
** File description:
** Created by Leo Fabre
*/
#include "raylib_encap/Window.hpp"

Window::Window(bool fullscreen)
    : screenSize(GetScreenWidth(), GetScreenHeight())
{
    SetTargetFPS(60);
    if (fullscreen) {
        InitWindow((int)screenSize.x, (int)screenSize.y, "Bomberman");
        ToggleFullscreen();
    } else {
        InitWindow(1280, 720, "Bomberman");
    }
    SetExitKey(0);
}

Window::~Window()
{
    CloseWindow();
}

bool Window::ShouldClose()
{
    return WindowShouldClose();
}

Vector2D Window::GetWinSize()
{
    return Vector2D(GetScreenWidth(), GetScreenHeight());
}

void Window::ToogleFullscreen()
{
    ToggleFullscreen();
}

bool Window::isFullScreen()
{
    return IsWindowFullscreen();
}
