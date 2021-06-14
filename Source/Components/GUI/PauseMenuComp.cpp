/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include "Components/GUI/PauseMenuComp.hpp"

void PauseMenuComp::init()
{
    Component::init();
    auto &ent = entity->_mgr.addEntity("ResumeBtn");
    auto pos = Vector2D(Vector2D::ScreenCenter().x - 135, Vector2D::ScreenCenter().y - 180);
    ent.addComponent<TransformComp>(pos);
    resume_btn =
        &ent.addComponent<ButtonComp>("Resume", Vector2D(270, 50), false);
    resume_btn->AddEventFunc([this]() {setIsPaused(false);});
    resume_btn->entity->addGroup(GUI);
    MenuButton();
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
    Menu_btn->setVisible(is_paused);
}

PauseMenuComp::PauseMenuComp()
    : _isPaused(false)
{
}

void PauseMenuComp::MenuButton() {
    auto winCenter = Vector2D::ScreenCenter();
    auto pos = Vector2D(Vector2D::ScreenCenter().x - 135, Vector2D::ScreenCenter().y - 100);
    auto &BackToMenuBtnEnt = entity->_mgr.addEntity("BackToMenuButton");
    BackToMenuBtnEnt.addComponent<TransformComp>(pos);
    Menu_btn = &BackToMenuBtnEnt.addComponent<ButtonComp>("Menu", Vector2D(270, 50));
    BackToMenuBtnEnt.getComponent<ButtonComp>().AddEventFunc(
            [this]() {
                entity->_mgr.setNextSceneToLoad(Manager::SceneType::MainMenu);
                entity->_mgr.setAlive(false);
            }
    );
    BackToMenuBtnEnt.addGroup(GUI);
    BackToMenuBtnEnt.getComponent<ButtonComp>().setVisible(false);
}
