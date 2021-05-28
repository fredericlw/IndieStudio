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

class EModel {
public:
    EModel(const std::string modpath, const std::string textpath);
    void draw(const Vector3D &pos);
    virtual ~EModel();
private:
    Texture texture;
    Model model;
};

#endif //EMODEL_HPP
