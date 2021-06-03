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
    void SpawnPlayer(
        std::string entityName, const Vector3D& pos, EInputType inputType,
        PlayerNum num,
        Colors color
    );
    void SpawnPlayers();
};

#endif //GAMELOGICCOMP_HPP
