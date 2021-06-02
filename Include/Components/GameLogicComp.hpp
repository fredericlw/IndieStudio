/*
** EPITECH PROJECT, 2023
** bomberman
** File description:
** Created by Adrien Courbebaisse
*/
#ifndef GAMELOGICCOMP_HPP
#define GAMELOGICCOMP_HPP

#include <Component.hpp>

class GameLogicComp : public Component{
public:
    void init() override;
    void update() override;
    void draw() override;
private:
    //Entity &p1;
    Entity *p2;
    Entity *p3;
    Entity *p4;
};

#endif //GAMELOGICCOMP_HPP
