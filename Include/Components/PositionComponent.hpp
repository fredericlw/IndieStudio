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
    explicit PositionComponent(int x = 0, int y = 0, int z = 0){
        xpos = x;
        ypos = y;
        zpos = z;
    }
private:
    int xpos;
    int ypos;
    int zpos;
};

#endif //POSITIONCOMPONENT_HPP