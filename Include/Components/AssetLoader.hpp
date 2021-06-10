/*
** EPITECH PROJECT, 2024
** AssetLoader.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef ASSETLOADER_HPP
#define ASSETLOADER_HPP

#include <raylib_encap/EModel.hpp>
#include <raylib_encap/EAnimatedModel.hpp>
#include <Component.hpp>
#include <raylib_encap/ESound.hpp>
#include <raylib_encap/EMusic.hpp>

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
    EModel FloorModel;
    EModel FullFireModel;
    EModel BombupModel;
    EModel SkateModel;
    EModel SoftBlockPassModel;
    EModel FireUpModel;
    ESound ExplosionSound;
    EMusic WalkingSound;
    float Volume;
};

#endif //ASSETLOADER_HPP