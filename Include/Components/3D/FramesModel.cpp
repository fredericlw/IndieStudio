//
// Created by leofa on 18/06/2021.
//

#include "FramesModel.hpp"
#include "Entity.hpp"

void FramesModel::init()
{
    Component::init();
    transform = &entity->getComponent<TransformComp>();
    if (!transform)
        transform = &entity->addComponent<TransformComp>();
}

void FramesModel::update()
{
    Component::update();
}

void FramesModel::draw()
{
    Component::draw();
    _curModel->draw(transform->position, color);
}

FramesModel::FramesModel(EFramesModel &firstModel, Colors color)
    : _curModel(&firstModel),
      color(color),
      transform(nullptr)
{
}

void FramesModel::SetModel(EFramesModel &newModel)
{
    _curModel = &newModel;
}

void FramesModel::SetSpeed(float Speed)
{
    _curModel->speed = Speed;
}
