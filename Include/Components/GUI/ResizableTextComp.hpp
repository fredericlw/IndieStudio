/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#ifndef RESIZABLETEXTCOMP_HPP
#define RESIZABLETEXTCOMP_HPP

#include <Component.hpp>
#include <raylib_encap/EText.hpp>
#include <3D/TransformComp.hpp>

class ResizableTextComp: public Component, public EText{
public:
    ResizableTextComp(const std::string &text, Colors color, int size);
    void init() override;
    void update() override;
    void draw() override;
private:
    Colors TextColor;
    TransformComp *transform;
    int size;
};

#endif //RESIZABLETEXTCOMP_HPP