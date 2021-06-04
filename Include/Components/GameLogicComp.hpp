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
    Player *p1;
    Player *p2;
    Player *p3;
    Player *p4;
    Player * SpawnPlayer(
        std::string entityName, const Vector3D& pos, EInputType inputType,
        PlayerNum num,
        Colors color
    );
    void SpawnPlayers();
    void SpawnPlayerHUD();
};

#endif //GAMELOGICCOMP_HPP
