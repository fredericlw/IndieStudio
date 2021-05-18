/*
** EPITECH PROJECT, 2024
** PositionComponent.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef POSITIONCOMPONENT_HPP
#define POSITIONCOMPONENT_HPP

#include <ECS/Component.hpp>

class PositionComponent : public Component {
public:
    int x();
    int y();
    int z();
    void setPos(int x, int y);
    void update() override;

private:
    int xpos = 0;
    int ypos = 0;
    int zpos = 0;
};

#endif //POSITIONCOMPONENT_HPP