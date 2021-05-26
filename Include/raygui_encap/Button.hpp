/*
** EPITECH PROJECT, 2024
** Button.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef BUTTON_HPP
#define BUTTON_HPP
#include "raygui.h"

class Button {
public:
    Button(const ERect& rect, std::string text);
    ~Button();
    bool draw();
private:
    ERect _rect;
    std::string _text;
};

#endif //BUTTON_HPP