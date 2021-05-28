/*
** EPITECH PROJECT, 2023
** bomberman
** File description:
** Created by Adrien Courbebaisse
*/
#include <iostream>
#include "raylib_encap/EModel.hpp"
#include "rlgl.h"
#include "raymath.h"

EModel::EModel(
    std::string modpath, std::string textpath, float scale
)
    : model(LoadModel(modpath.c_str())),
      texture(LoadTexture(textpath.c_str())),
      scale(scale)
{
   model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
}

void EModel::draw(const Vector3D &pos)
{
    DrawModel(model, pos, scale, WHITE);
}

EModel::EModel(const std::string modpath, Colors colors, float scale)
    : model(LoadModel(modpath.c_str())),
    scale(scale)
{
    Image image = GenImageColor(1, 1, GetRaylibColor(colors));
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
    model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
}

EModel::~EModel()
{
    UnloadTexture(texture);     // Unload texture
    UnloadModel(model);
}

void EModel::rotate(const Vector3D &vec)
{
   model.transform = MatrixRotateXYZ(vec);
}
