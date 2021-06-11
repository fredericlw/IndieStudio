/*
** EPITECH PROJECT, 2023
** bomberman
** File description:
** Created by Adrien Courbebaisse
*/
#ifndef GAMELOGICCOMP_HPP
#define GAMELOGICCOMP_HPP

#include <Component.hpp>
#include <AssetLoader.hpp>

class GameLogicComp : public Component{
public:
    enum GameState{Game, GameOver};
    void init() override;
    void update() override;
    void draw() override;
private:
    PlayerComp *p1;
    PlayerComp *p2;
    PlayerComp *p3;
    PlayerComp *p4;
    PlayerComp * SpawnPlayer(
        std::string entityName, const Vector3D& pos, EInputType inputType,
        PlayerNum num,
        Colors color
    );
    GameState gameState = Game;
    void SpawnPlayers();
    void SpawnPlayerHUD();
    std::array<PlayerComp *, 4> players;
    std::array<int, 4> playerScores;
    void update_game();
    void update_gameOver();
};

#endif //GAMELOGICCOMP_HPP
