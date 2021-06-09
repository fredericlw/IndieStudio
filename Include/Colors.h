/*
** EPITECH PROJECT, 2024
** Colors.h
** File description:
** Created by Leo Fabre
*/
#ifndef COLORS_H
#define COLORS_H

#include <iostream>

enum Colors {
    Green,
    Gray,
    LightGray,
    White,
    RayWhite,
    Red,
    DarkBlue,
    DarkGray,
    Black,
    Blue,
    Purple
};

static Color GetRaylibColor(Colors color){
    switch (color) {
    case Green:
        return GREEN;
    case Gray:
        return GRAY;
    case LightGray:
        return LIGHTGRAY;
    case White:
        return WHITE;
    case RayWhite:
        return RAYWHITE;
    case Red:
        return RED;
    case DarkBlue:
        return DARKBLUE;
    case DarkGray:
        return DARKGRAY;
    case Black:
        return BLACK;
    case Blue:
        return BLUE;
    case Purple:
        return PURPLE;
    default:
        std::cerr << "Bad color" << std::endl;
        return WHITE;
    }
}
#endif //COLORS_H