/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include "PauseMenuComp.hpp"

void PauseMenuComp::init()
{
    Component::init();
    auto &ent = entity->_mgr.addEntity("ResumeBtn");
    auto pos = Vector2D(Vector2D::ScreenCenter().x - 135, Vector2D::ScreenCenter().y - 25);
    ent.addComponent<TransformComp>(pos);
    resume_btn =
        &ent.addComponent<ButtonComp>("Resume", Vector2D(270, 50), false);
    resume_btn->AddEventFunc([this]() {setIsPaused(false);});
    resume_btn->entity->addGroup(GUI);

    auto &save = entity->_mgr.addEntity("ResumeBtn");
    save.addComponent<TransformComp>(Vector2D::ScreenCenter());
    resume_btn =
        &save.addComponent<ButtonComp>("Resume", Vector2D(270, 50), false);
    resume_btn->AddEventFunc([this]() {setIsPaused(false);});
    resume_btn->entity->addGroup(GUI);
}

void PauseMenuComp::update()
{
    Component::update();
}

void PauseMenuComp::draw()
{
    Component::draw();
}

bool PauseMenuComp::isIsPaused() const
{
    return _isPaused;
}

void PauseMenuComp::setIsPaused(bool is_paused)
{
    std::cout << "PAUSE" << std::endl;
    _isPaused = is_paused;
    resume_btn->setVisible(is_paused);
}

PauseMenuComp::PauseMenuComp()
    : _isPaused(false)
{
}
