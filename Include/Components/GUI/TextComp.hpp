/*
** EPITECH PROJECT, 2024
** TextComp.hpp
** File description:
** Created by Frederic LAWECKI--WALKOWIAK
*/

#ifndef BOMBERMAN_TEXTCOMP_HPP
#define BOMBERMAN_TEXTCOMP_HPP

#include <Component.hpp>
#include <raylib_encap/EText.hpp>
#include <3D/TransformComp.hpp>

class TextComp : public Component, public EText{
public:
    TextComp(const std::string &text, Colors color);
    void init() override;
    void update() override;
    void draw() override;
private:
    Colors TextColor;
    TransformComp *transform;
};


#endif //BOMBERMAN_TEXTCOMP_HPP
