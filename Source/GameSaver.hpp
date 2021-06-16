/*
** EPITECH PROJECT, 2024
** GameSaver.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef GAMESAVER_HPP
#define GAMESAVER_HPP

#include <vector>
#include <raylib_encap/Math/Vector3D.hpp>
#include <array>

class GameSaver {
public:
    GameSaver();
    ~GameSaver();
    struct PlayerInfo{
        Vector3D pos;
        int points;
        bool alive;
    };
    struct GameSave{
        std::vector<Vector3D> obstacles;
        std::array<PlayerInfo, 4> players;
    };
private:
};

#endif //GAMESAVER_HPP