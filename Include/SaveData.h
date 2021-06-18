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
#include <ostream>
#include "Character/powerup.hpp"
#include "Keys.h"

//region Data saving structures
struct PowerUpData {
    template<class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & pos & type;
    }
    Vector3D pos;
    PowerUpType type;
};

struct BombData{
    template<class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & pos & timeAlive & owner;
    }
    float timeAlive;
    Vector3D pos;
    PlayerNum owner;

    friend std::ostream &operator<<(std::ostream &os, const BombData &data)
    {
        os << "timeAlive: " << data.timeAlive << " pos: " << data.pos
            << " owner: " << data.owner;
        return os;
    }
};

struct PlayerData {
    template<class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & pos & powerUp & score & isAlive & activeBombs;
    }
    Vector3D pos;
    PowerUpType powerUp;
    int score;
    bool isAlive;
    int activeBombs;

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
        ar & obstacles & players & bombs & powerUps;
    }
    //actual game data
    std::vector<Vector3D> obstacles;
    std::array<PlayerData, 4> players;
    std::vector<BombData> bombs;
    std::vector<PowerUpData> powerUps;
};
//endregion

#endif //SAVEDATA_H