/*
** EPITECH PROJECT, 2023
** bomberman
** File description:
** Created by Adrien Courbebaisse
*/
#include "ModelComp.hpp"
#include "ECS/Entity.hpp"
#include "Manager.hpp"

ModelComp::ModelComp(std::string modelPath, std::string texturePath)
    : model(modelPath, texturePath)
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
    entity->_mgr.MainCam.Begin3D();
    model.draw(transform->position);
    entity->_mgr.MainCam.End3D();
}

void ModelComp::update()
{
    Component::update();
}
