/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by Achille Bourgault
*/

#ifndef BOMBCOMP
#define BOMBCOMP

#include <3D/TransformComp.hpp>
#include <3D/BasicCubeComp.hpp>
#include "Component.hpp"
#include <ctime>
#include <3D/ModelComp.hpp>
#include <Character/Player.hpp>
#include "raylib_encap/ESound.hpp"

class BombComp : public Component {
public:
    BombComp(Colors color, Player *owner);
    void init() override;
    void update() override;
    void draw() override;
private:
    void explode();
    std::time_t spawnTime;
    TransformComp *_transform;
    ModelComp *model;
    Colors _color;
    std::vector<Entity *> particles;
    Player *_owner;
    ESound *_explosion_sound;

    void GenerateParticles();
    void SpawnParticle(Vector3D &pos);
    bool hasExploded;
    bool particlesCleared;
    bool checkCol(
        const Vector3D &mapPos, const ECube &flameCube, ECube &wallCube,
        Vector3D &wallCubePos, std::vector<Vector2D> &walls
    ) const;
};

#endif //BOMBERMAN_BOMBCOMP_HPP