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
    EMeshCube(const Vector3D &size = Vector3D::One(), std::string sprPath = "");
    virtual ~EMeshCube();
    void draw(const Vector3D &pos);
private:
    Model _model;
    Mesh _meshCube;
    Material _mat;
    ESprite _sprite;
    Vector3D _size;
};

#endif //EMESHCUBE_HPP
