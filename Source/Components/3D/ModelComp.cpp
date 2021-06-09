/*
** EPITECH PROJECT, 2023
** bomberman
** File description:
** Created by Adrien Courbebaisse
*/
#include "Components/3D/ModelComp.hpp"

#include <utility>
#include "ECS/Entity.hpp"
#include "Manager.hpp"

ModelComp::ModelComp(
    std::string modelPath, std::string texturePath, float scale
)
    : model(std::move(modelPath), std::move(texturePath), scale),
      _baseScale(scale),
      shouldDrawColor(false),
      Offset(Vector3D::Zero())
{
}

ModelComp::ModelComp(std::string modelPath, Colors colors, float scale)
    : model(std::move(modelPath), colors, scale),
      _baseScale(scale),
      shouldDrawColor(true),
      Offset(Vector3D::Zero())
{
}

ModelComp::ModelComp(std::string modelPath, float scale)
    : model(std::move(modelPath), scale),
      _baseScale(scale),
      shouldDrawColor(true),
      Offset(Vector3D::Zero())
{
}

ModelComp::ModelComp(const EModel &model, Colors color)
    : model(model),
      _baseScale(model.scale),
      _color(color),
      shouldDrawColor(true),
      Offset(Vector3D::Zero())
{
}

ModelComp::ModelComp(const EModel &model)
    : model(model),
      _baseScale(model.scale),
      shouldDrawColor(false),
      Offset(Vector3D::Zero())
{
}

void ModelComp::init()
{
    Component::init();
    transform = &entity->getComponent<TransformComp>();
    if (!transform) {
        transform = &entity->addComponent<TransformComp>();
    }
}

void ModelComp::draw()
{
    Component::draw();
    if (model.scale == 0)
        return;
    Vector3D drawPos(transform->position);
    drawPos.Add(Offset);
    entity->_mgr.MainCam.Begin3D();
    if (shouldDrawColor) {
        model.draw(drawPos, _color);
    } else
        model.draw(drawPos);
    entity->_mgr.MainCam.End3D();
}

void ModelComp::update()
{
    Component::update();
}

void ModelComp::rotate(const Vector3D &vec)
{
    model.rotate(vec);
}

void ModelComp::SetVisibility(bool state)
{
    if (state)
        model.scale = _baseScale;
    else
        model.scale = 0;
}

//region get/set

const Vector3D &ModelComp::getOffset() const
{
    return Offset;
}

void ModelComp::setOffset(const Vector3D &offset)
{
    Offset = offset;
}

Mesh ModelComp::getMesh()
{
    return model.getMesh();
}

Material ModelComp::getMat()
{
    return model.model.materials[0];
}

//endregion


