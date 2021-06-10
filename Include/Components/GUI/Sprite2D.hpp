/*
** EPITECH PROJECT, 2024
** Sprite2D.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef SPRITE2D_HPP
#define SPRITE2D_HPP

#include <ECS/Component.hpp>
#include <raylib.h>
#include <raylib_encap/ESprite.hpp>
#include "Components/3D/TransformComp.hpp"

class Sprite2D : public Component, public ESprite {
public:
    explicit Sprite2D(const std::string &path);
    Sprite2D(ESprite &sprite);
    void init() override;
    void update() override;
    void draw() override;
private:
    TransformComp *transform;
};

#endif //SPRITE2D_HPP