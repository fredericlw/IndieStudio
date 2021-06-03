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

ModelComp::ModelComp(std::string modelPath, std::string texturePath, float scale)
    : model(std::move(modelPath), std::move(texturePath), scale)
{
}

ModelComp::ModelComp(std::string modelPath, Colors colors, float scale)
    : model(std::move(modelPath), colors, scale)
{
}

ModelComp::ModelComp(std::string modelPath, float scale)
    : model(std::move(modelPath), scale)
{
    std::cout << "MODELCOMP CTOR" << std::endl;
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
    entity->_mgr.MainCam.Begin3D();
    model.draw(transform->position);
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
