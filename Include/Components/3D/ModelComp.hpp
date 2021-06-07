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

class ModelComp : public Component {
public:
    ModelComp(std::string modelPath, std::string texturePath, float scale);
    ModelComp(std::string modelPath, Colors colors, float scale);
    ModelComp(std::string modelPath, float scale);
    void update() override;
    void rotate(const Vector3D &vec);
    void draw() override;
    void init() override;
    void SetVisibility(bool state);
private:
    EModel model;
    TransformComp *transform;
    float _baseScale;
};

#endif //MODELCOMP_HPP
