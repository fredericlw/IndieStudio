/*
** EPITECH PROJECT, 2024
** PowerUpComp.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef POWERUPCOMP_HPP
#define POWERUPCOMP_HPP

#include <Character/powerup.hpp>
#include <raylib_encap/EModel.hpp>
#include <3D/ModelComp.hpp>
#include <3D/BasicCubeComp.hpp>
#include "Component.hpp"

class PowerUpComp : public Component{
public:
    PowerUpType type;
    void init() override;
    void draw() override;
    PowerUpComp();
    ~PowerUpComp();
    ModelComp *model;
    BasicCubeComp *collider;
private:
};

#endif //POWERUPCOMP_HPP