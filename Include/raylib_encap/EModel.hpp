/*
** EPITECH PROJECT, 2023
** bomberman
** File description:
** Created by Adrien Courbebaisse
*/
#ifndef EMODEL_HPP
#define EMODEL_HPP

#include <raylib_encap/Math/Vector3D.hpp>
#include "raylib.h"
#include "ESprite.hpp"
#include "Colors.h"

class EModel {
public:
    EModel(
        std::string modpath, std::string textpath, float scale
    );
    EModel(const std::string& modpath, Colors colors, float scale);
    EModel(const std::string& modpath, float scale);
    void rotate(const Vector3D &vec);
    void draw(const Vector3D &pos, Colors color = White);
    void transpose(const Vector3D &vec);
    virtual ~EModel();
    float scale;
    Mesh &getMesh();
    void Unload();
    Model model;
private:
    Texture texture;
    Texture2D GenTex();
};

#endif //EMODEL_HPP
