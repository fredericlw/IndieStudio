/*
** EPITECH PROJECT, 2023
** bomberman
** File description:
** Created by Adrien Courbebaisse
*/
#include <iostream>
#include "raylib_encap/EModel.hpp"

EModel::EModel(std::string modpath, std::string textpath)
    : model(LoadModel(modpath.c_str())),
    texture(LoadTexture(textpath.c_str()))
{
   model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
}

void EModel::draw(const Vector3D &pos)
{
    DrawModel(model, pos, 3.0f, WHITE);
}

EModel::~EModel()
{
    UnloadTexture(texture);     // Unload texture
    UnloadModel(model);
}
