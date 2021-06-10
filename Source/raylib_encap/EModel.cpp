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
    model.materials[1].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
}

//for .OBJs that link to a .mat file (== material is provided)
EModel::EModel(const std::string& modpath, float scale)
    : model(LoadModel(modpath.c_str())),
      scale(scale)
{
    Image image = GenImageColor(1, 1, GetRaylibColor(LightGray));
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
//    model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
}

void EModel::draw(const Vector3D &pos, Colors color)
{
    DrawModel(model, pos, scale, GetRaylibColor(color));
}

EModel::EModel(const std::string &modpath, Colors colors, float scale)
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
//    UnloadTexture(texture);     // Unload texture
//    UnloadModel(model); //this produces segfault when using assetLoader
}

void EModel::rotate(const Vector3D &vec)
{
    model.transform = MatrixRotateXYZ(vec);
}

Mesh &EModel::getMesh()
{
    return model.meshes[0];
}

void EModel::Unload()
{
    UnloadModel(model);
}
