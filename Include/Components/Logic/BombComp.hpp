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
    ECube collider;
    enum Way {Left, Down, Up, Right};
private:
    void GenerateParticles();
    bool SpawnParticle(Vector3D &pos);
    bool hasExploded;
    bool particlesCleared;
    bool checkCol(
        const Vector3D &mapPos, const ECube &flameCube, ECube &wallCube,
        Vector3D &wallCubePos, std::vector<Entity *> walls
    ) const;
    void checkPlayer(Vector3D pos);
    bool checkWall(Vector3D pos);
    bool checkObstacle(Vector3D pos);
    void spreadExplosion(Way way);
public:
    const ECube &getCube() const;
    float _curParticleScale;
    float _baseParticleSize;
    clock_t _particleStartTime;
};

#endif //BOMBERMAN_BOMBCOMP_HPP
