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
#include <boost/serialization/vector.hpp>
#include <boost/serialization/array.hpp>
#include <ostream>
#include <Logic/GameLogicComp.hpp>
#include "Logic/MapComponent.hpp"
#include "SaveData.h"

class GameSaveLoad {
public:
    static GameSaveData loadDataFromSaveFile();
    static void SaveGameToFile(GameLogicComp &gamelogic);
    static GameSaveData getSaveData(GameLogicComp &gamelogic);
private:
    static std::vector<Vector3D> getObstacles(MapComponent &mapComp);
    static std::array<PlayerData, 4> getPlayersData(GameLogicComp &comp);
    static std::vector<BombData> getBombsData(GameLogicComp &gl);
};

#endif //GAMESAVELOAD_HPP