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

//for .OBJs that link to a .mat file (== material is provided)
EModel::EModel(const std::string modpath, float scale)
    : model(LoadModel(modpath.c_str())),
      scale(scale),
      texture(GenTex())
{
    std::cout << "EMODEL CTOR" << std::endl;
}

void EModel::draw(const Vector3D &pos)
{
    DrawModel(model, pos, scale, WHITE);
}

EModel::EModel(const std::string& modpath, Colors colors, float scale)
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

Texture2D EModel::GenTex()
{
    std::cout << "GENERATING TEXTURE" << std::endl;
    int width = 960;
    int height = 480;
    // Dynamic memory allocation to store pixels data (Color type)
    Color *pixels = (Color *)malloc(width*height*sizeof(Color));

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (((x/32+y/32)/1)%2 == 0) pixels[y*width + x] = ORANGE;
            else pixels[y*width + x] = GOLD;
        }
    }

    // Load pixels data into an image structure and create texture
    Image checkedIm = {
        .data = pixels,             // We can assign pixels directly to data
        .width = width,
        .height = height,
        .mipmaps = 1,
        .format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8
    };

    Texture2D checked = LoadTextureFromImage(checkedIm);
    UnloadImage(checkedIm);         // Unload CPU (RAM) image data (pixels)
    return checked;
}
