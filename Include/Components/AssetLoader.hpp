/*
** EPITECH PROJECT, 2024
** AssetLoader.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef ASSETLOADER_HPP
#define ASSETLOADER_HPP

#include <raylib_encap/EModel.hpp>
#include <Component.hpp>

class AssetLoader : public Component {
public:
    void init() override;
    AssetLoader();
    ~AssetLoader();
    EModel PlayerModel;
    EModel StoneCubeModel;
    EModel BombModel;
    EModel ObstacleModel;
};

#endif //ASSETLOADER_HPP