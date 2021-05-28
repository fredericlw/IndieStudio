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
    ~Window();
    bool ShouldClose();
private:
    std::tuple<int,int> screenSize;
};

#endif //WINDOW_HPP