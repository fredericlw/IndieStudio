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
    void draw(int posX, int posY, int size);
    void drawInRectCenter(ERect rect, int size);
    std::string _text;
    void setColor(Colors color);
private:
    Colors _color;
};

#endif //ETEXT_HPP