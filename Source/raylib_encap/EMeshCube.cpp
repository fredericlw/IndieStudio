/*
** EPITECH PROJECT, 2023
** bomberman
** File description:
** Created by Adrien Courbebaisse
*/
#include "raylib_encap/EMeshCube.hpp"
#include "raylib.h"

EMeshCube::EMeshCube(const Vector3D &size, std::string sprPath)
    : _size(size),
      _sprite(sprPath)
{
    _meshCube = GenMeshCube(_size.x, _size.y, _size.z);
    SetMaterialTexture(_mat, MATERIAL_MAP_DIFFUSE, _sprite.getTex());
}

void EMeshCube::draw(const Vector3D &poz, Matrix matrix)
{
    DrawMesh(_meshCube, *_mat, matrix);
}
