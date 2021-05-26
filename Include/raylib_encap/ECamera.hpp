/*
** EPITECH PROJECT, 2024
** ECamera.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef ECAMERA_HPP
#define ECAMERA_HPP

#include <raylib.h>

class ECamera : public Camera3D {
public:
    ECamera();
    ~ECamera();
    void Begin3D();
    void End3D();
};

#endif //ECAMERA_HPP