/*
** EPITECH PROJECT, 2024
** MovementComp.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef MOVEMENTCOMP_HPP
#define MOVEMENTCOMP_HPP

#include <raylib_encap/Input/AInputModule.hpp>
#include <3D/TransformComp.hpp>
#include <3D/BasicCubeComp.hpp>

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
    AInputModule *_inputMod;
    void GenerateInputModule(EInputType type, PlayerNum num);
    Vector3D Velocity;
    float _speed;
public:
    float getSpeed() const;
    void setSpeed(float speed);
    AInputModule *getInputModule();
};

#endif //MOVEMENTCOMP_HPP