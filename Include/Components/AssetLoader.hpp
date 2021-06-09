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
#include "../../Source/raylib_encap/EAnimatedModel.hpp"

class AssetLoader : public Component {
public:
    void init() override;
    AssetLoader();
    ~AssetLoader();
    EModel PlayerModel;
    EModel StoneCubeModel;
    EModel BombModel;
    EModel ObstacleModel;
    EModel ExplosionModel;
    EAnimatedModel ExplosionAnim;
};

#endif //ASSETLOADER_HPP