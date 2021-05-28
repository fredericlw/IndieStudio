/*
** EPITECH PROJECT, 2023
** bomberman
** File description:
** Created by Adrien Courbebaisse
*/
#ifndef MODELCOMP_HPP
#define MODELCOMP_HPP

#include <ECS/Component.hpp>
#include <raylib_encap/Math/Vector3D.hpp>
#include <raylib_encap/EModel.hpp>
#include "TransformComp.hpp"

class ModelComp : public Component
    {
    public:
    ModelComp(std::string modelPath, std::string texturePath);
    void update() override;
    void draw() override;
    void init() override;
private:
    EModel model;
    TransformComp *transform;
};

#endif //MODELCOMP_HPP
