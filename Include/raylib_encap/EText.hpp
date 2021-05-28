/*
** EPITECH PROJECT, 2024
** EText.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef ETEXT_HPP
#define ETEXT_HPP

#include <string>
#include "ERect.hpp"

class EText {
public:
    EText(std::string text);
    ~EText();
    void draw(int posX, int posY, int size, Colors _color);
    void drawCentered(int posX, int posY, int size, Colors _color);
    void drawInRectCenter(ERect rect, int size, Colors _color);
    std::string _text;
};

#endif //ETEXT_HPP