/*
** EPITECH PROJECT, 2023
** bomberman
** File description:
** Created by Adrien Courbebaisse
*/
#ifndef CUBECOLLIDER_HPP
#define CUBECOLLIDER_HPP

#include "raylib.h"
#include "raylib_encap/ECube.hpp"

class CubeCollider {
public:
    static bool CheckBoxOverLap(BoundingBox A, BoundingBox B);
    static bool CheckBoxOverLap(const ECube& A, const ECube& B);
};

#endif //CUBECOLLIDER_HPP
