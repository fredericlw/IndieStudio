/*
** EPITECH PROJECT, 2024
** Window.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef WINDOW_HPP
#define WINDOW_HPP
#include <raylib.h>
#include <tuple>
#include <raylib_encap/Math/Vector2D.hpp>

class Window {
public:
    static Vector2D GetWinSize();
    Window(bool fullscreen);
    static void ToogleFullscreen();
    static bool isFullScreen();
    ~Window();
    bool ShouldClose();
private:
    Vector2D screenSize;
};

#endif //WINDOW_HPP