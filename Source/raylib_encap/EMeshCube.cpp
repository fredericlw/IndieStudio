/*
** EPITECH PROJECT, 2023
** bomberman
** File description:
** Created by Adrien Courbebaisse
*/
#include <iostream>
#include "raylib_encap/EMeshCube.hpp"
#include "raylib.h"

EMeshCube::EMeshCube(const Vector3D &size, std::string sprPath)
    : _mat(LoadMaterialDefault()),
      _size(size),
      _sprite(sprPath)
{
    _meshCube = GenMeshCube(_size.x, _size.y, _size.z);
    _model = LoadModelFromMesh(_meshCube);
    SetMaterialTexture(&_mat, MATERIAL_MAP_DIFFUSE, _sprite);
    std::cout << "SET MATERIAL TEX OK" << std::endl;
}

void EMeshCube::draw(const Vector3D &pos)
{
    std::cout << "Drawing cube. pos : " << pos << std::endl;
    DrawModel(_model, pos, 10, WHITE);
}

EMeshCube::~EMeshCube()
{
}
