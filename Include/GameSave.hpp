/*
** EPITECH PROJECT, 2024
** GameSave.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef GAMESAVE_HPP
#define GAMESAVE_HPP

#include <vector>
#include <raylib_encap/Math/Vector3D.hpp>
#include <array>
#include <Character/powerup.hpp>

class GameSave {
public:
    GameSave();
    ~GameSave();
    //todo save bombs ???
    struct PlayerData{
        Vector3D pos;
        PowerUpType powerUp;
        bool isAlive;
    };
private:
    std::vector<Vector3D> obstacles;
    std::array<PlayerData, 4> players;
};

#endif //GAMESAVE_HPP