/*
** EPITECH PROJECT, 2024
** AnimatedModel.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef ANIMATEDMODEL_HPP
#define ANIMATEDMODEL_HPP

#include <Component.hpp>
#include <3D/TransformComp.hpp>
#include "../../../Source/raylib_encap/EAnimatedModel.hpp"

class AnimatedModel : public Component {
public:
    AnimatedModel(EAnimatedModel& model);
    void init() override;
    void update() override;
    void draw() override;
    void setScale(float scale);
    void reset();
private:
    EAnimatedModel *_model;
    TransformComp *transform;
};

#endif //ANIMATEDMODEL_HPP