/*
** EPITECH PROJECT, 2024
** MovementComp.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef MOVEMENTCOMP_HPP
#define MOVEMENTCOMP_HPP

#include <raylib_encap/Input/AInputModule.hpp>
#include "Components/Components.h"

#define BASESPEED .25f

class MovementComp : public Component {
public:
    MovementComp(EInputType input_type, PlayerNum num);
    ~MovementComp();
    void update() override;
    void init() override;
private:
    TransformComp *transform;
    BasicCubeComp *cube;
    std::unique_ptr<AInputModule> _inputMod;
    void GenerateInputModule(EInputType type, PlayerNum num);
    Vector3D Velocity;
    float _speed;
public:
    float getSpeed() const;
    void setSpeed(float speed);
};

#endif //MOVEMENTCOMP_HPP