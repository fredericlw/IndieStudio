/*
** EPITECH PROJECT, 2024
** SaveData.h
** File description:
** Created by Leo Fabre
*/
#ifndef SAVEDATA_H
#define SAVEDATA_H

#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/array.hpp>
#include "Character/powerup.hpp"

//region Data saving structures
//todo save bombs ??? powerups ???
struct PlayerData {
    template<class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & pos & powerUp & score & isAlive;
    }
    Vector3D pos;
    PowerUpType powerUp;
    int score;
    bool isAlive;

    friend std::ostream &operator<<(
        std::ostream &os, const PlayerData &data
    )
    {
        os << "pos: " << data.pos << " powerUp: " << data.powerUp
            << " score: " << data.score << " isAlive: " << data.isAlive;
        return os;
    }
};

struct GameSaveData {
    //boost serialization code
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & obstacles & players;
    }
    //actual game data
    std::vector<Vector3D> obstacles;
    std::array<PlayerData, 4> players;
};
//endregion

#endif //SAVEDATA_H