/*
** EPITECH PROJECT, 2024
** ButtonComp.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef BUTTONCOMP_HPP
#define BUTTONCOMP_HPP
#include "ECS/Component.hpp"

class ButtonComp :public Component{
public:
    ButtonComp(const std::string &spritePath);
    ~ButtonComp();
private:
};

#endif //BUTTONCOMP_HPP