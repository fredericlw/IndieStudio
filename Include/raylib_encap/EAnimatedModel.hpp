/*
** EPITECH PROJECT, 2024
** EAnimatedModel.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef EANIMATEDMODEL_HPP
#define EANIMATEDMODEL_HPP

#include <raylib.h>
#include <string>
#include <raylib_encap/EModel.hpp>

class EAnimatedModel {
public:
    EAnimatedModel(
        const std::string &path, EModel& model
    );
    ~EAnimatedModel();
    ModelAnimation *animations;
    int animFrameCounter;
    EModel *model;
    void update();
    void draw(Vector3D pos);
    unsigned int animCount;
    void Unload();
};

#endif //EANIMATEDMODEL_HPP