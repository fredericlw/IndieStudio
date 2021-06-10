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

    ModelComp(const EModel &model);
    ModelComp(const EModel &model, Colors color);

    void update() override;
    void rotate(const Vector3D &vec);
    void draw() override;
    void init() override;
    void SetVisibility(bool state);
    Mesh getMesh();
    Material getMat();
    EModel model;
private:
    TransformComp *transform;
    float _baseScale;
public:
    float getBaseScale() const;
private:
    Colors _color;
private:
    bool shouldDrawColor;
    Vector3D Offset;
public:
    const Vector3D &getOffset() const;
    void setOffset(const Vector3D &offset);
    void setModelScale(const float &scale);
};

#endif //MODELCOMP_HPP
