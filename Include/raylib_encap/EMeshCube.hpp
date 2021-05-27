/*
** EPITECH PROJECT, 2023
** bomberman
** File description:
** Created by Adrien Courbebaisse
*/
#ifndef EMESHCUBE_HPP
#define EMESHCUBE_HPP

#include <raylib_encap/Math/Vector3D.hpp>
#include "raylib.h"
#include "ESprite.hpp"


class EMeshCube {
public:
    EMeshCube(const Vector3D &size, std::string sprPath);
    void draw(const Vector3D &poz, Matrix matrix);
private:
    Mesh _meshCube;
    Material *_mat;
    ESprite _sprite;
    Vector3D _size;
};

#endif //EMESHCUBE_HPP
