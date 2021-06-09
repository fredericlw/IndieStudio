/*
** EPITECH PROJECT, 2024
** AnimatedModel.cpp
** File description:
** Created by Leo Fabre
*/
#include "Components/3D/AnimatedModel.hpp"
#include "Entity.hpp"

#include "Manager.hpp"

AnimatedModel::AnimatedModel(EAnimatedModel& model)
: _model(&model)
{
}


void AnimatedModel::init()
{
    Component::init();
    transform = &entity->getComponent<TransformComp>();
    if (!transform) {
        transform = &entity->addComponent<TransformComp>();
    }
}

void AnimatedModel::update()
{
    Component::update();
    _model->update();
}

void AnimatedModel::draw()
{
    Component::draw();
    entity->_mgr.MainCam.Begin3D();
    _model->draw(transform->position);
    entity->_mgr.MainCam.End3D();
}
