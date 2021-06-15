/*
** EPITECH PROJECT, 2024
** GameSaveLoad.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef GAMESAVELOAD_HPP
#define GAMESAVELOAD_HPP

#include <vector>
#include <raylib_encap/Math/Vector3D.hpp>
#include <array>
#include <Character/powerup.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <Logic/GameLogicComp.hpp>

class GameSaveLoad {
public:
    //todo save bombs ???
    struct PlayerData {
        Vector3D pos;
        PowerUpType powerUp;
        bool isAlive;
    };

    struct GameSaveData {
        //boost serialization code
        friend class boost::serialization::access;
        template<class Archive>
        void serialize(Archive &ar, const unsigned int version)
        {
            ar & obstacles;
            ar & players;
        }
        //actual game data
        std::vector<Vector3D> obstacles;
        std::array<PlayerData, 4> players;
    };
    static GameSaveData getSaveData(GameLogicComp &gamelogic);
private:
    static std::vector<Vector3D> getObstacles(MapComponent &mapComp);
    static std::array<PlayerData, 4> getPlayersData(GameLogicComp &comp);
};

#endif //GAMESAVELOAD_HPP