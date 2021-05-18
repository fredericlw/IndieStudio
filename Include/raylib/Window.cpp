/*
** EPITECH PROJECT, 2024
** Window.cpp
** File description:
** Created by Leo Fabre
*/
#include "Window.hpp"

Window::Window(bool fullscreen) :screenSize(std::make_tuple(GetScreenWidth(), GetScreenHeight()))
{
    if (fullscreen) {
        InitWindow(get<0>(screenSize), get<1>(screenSize), "Bomberman");
        ToggleFullscreen();
    } else {
        InitWindow(800, 600, "Bomberman");
    }
}

Window::~Window()
{

}
