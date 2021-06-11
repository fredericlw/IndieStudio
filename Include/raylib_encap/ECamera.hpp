/*
** EPITECH PROJECT, 2024
** ECamera.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef ECAMERA_HPP
#define ECAMERA_HPP

#include <raylib.h>
#include <raylib_encap/Math/Vector2D.hpp>

class ECamera : public Camera {
public:
    ECamera();
    ~ECamera();
    void Begin3D();
    void End3D();
    void Begin2D();
    void End2D();
    Matrix getMatrix();
    Vector2D WorldToScreen(Vector3D pos);
    void Update();
};

#endif //ECAMERA_HPP