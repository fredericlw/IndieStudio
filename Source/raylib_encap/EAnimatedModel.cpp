/*
** EPITECH PROJECT, 2024
** EAnimatedModel.cpp
** File description:
** Created by Leo Fabre
*/
#include "raylib_encap/EAnimatedModel.hpp"

EAnimatedModel::EAnimatedModel(
    const std::string &path, EModel &model
)
    : animCount(0),
      animations(LoadModelAnimations(path.c_str(), &animCount)),
      model(&model)
{
    std::cout << "ANIM VALID ? : "
        << IsModelAnimationValid(model.model, animations[0]) << std::endl;
    std::cout << "ANIM 0 FRAMECOUNT : " << animations[0].frameCount
        << std::endl;
    std::cout << "ANIM COUNT" << animCount << std::endl;
}

void EAnimatedModel::update()
{
    animFrameCounter++;
//    std::cout << "coucou anim frame " << animFrameCounter << std::endl;
    UpdateModelAnimation(model->model, animations[0], animFrameCounter / 3);
    if (animFrameCounter / 3 >= animations[0].frameCount) animFrameCounter = 0;
}

EAnimatedModel::~EAnimatedModel()
{
}

void EAnimatedModel::draw(Vector3D pos)
{
    DrawModelEx(model->model, pos, {1, 0, 0}, -90,
        Vector3D::One().Multiply(model->scale), WHITE);
    GetFrameTime();
}
