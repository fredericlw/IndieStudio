/*
** EPITECH PROJECT, 2024
** TransformComp.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef TRANSFORMCOMP_HPP
#define TRANSFORMCOMP_HPP

#include <ECS/Component.hpp>
#include <raylib.h>
#include "raylib/Vector3D.hpp"

class TransformComp : public Component {
public:
    void update() override;
    explicit TransformComp(float x = 0, float y = 0, float z = 0);
    explicit TransformComp(const Vector3D& Position);
    Vector3D position;
};

#endif //TRANSFORMCOMP_HPP