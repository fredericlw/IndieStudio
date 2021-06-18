//
// Created by leofa on 18/06/2021.
//

#include <raylib_encap/ETime.hpp>
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
    if (!visible) {return;}
    _curModel.draw(transform->position, color);
    if (entity->getName() == "Player 1") {
        std::cout << "DRAWING " << ETime::DeltaTime() << std::endl;
    }
}

FramesModel::FramesModel(EFramesModel &firstModel, Colors color)
    : _curModel(EFramesModel(firstModel)),
      color(color),
      transform(nullptr),
      visible(true)
{
}

void FramesModel::SetModel(EFramesModel &newModel)
{
    _curModel = newModel;
}

void FramesModel::SetSpeed(float Speed)
{
    _curModel.speed = Speed;
}

void FramesModel::rotate(const Vector3D &vec)
{
    _curModel.rotate(vec);
}

void FramesModel::SetVisibility(bool state)
{
    visible = state;
    std::cout << "SET VISIBLE TO " << state << std::endl;
}
