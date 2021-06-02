/*
** EPITECH PROJECT, 2023
** bomberman
** File description:
** Created by Adrien Courbebaisse
*/
#include "Components/GUI/LobbyComp.hpp"
#include "Entity.hpp"
#include "Manager.hpp"

void LobbyComp::AddListSelector()
{
    std::vector<std::string> list = {"IA", "Keyboard", "Gamepad"};

    addSel(
        list, "First PLayer", Blue,
        Vector2D::ScreenCenter().Subtract({450, -200}), "PLayer 1");
    addSel(
        list, "Second PLayer", Green,
        Vector2D::ScreenCenter().Subtract({150, -200}), "PLayer 2");
    addSel(
        list, "Third PLayer", Red,
        Vector2D::ScreenCenter().Subtract({-150, -200}), "PLayer 3");
    addSel(
        list, "Fourth PLayer", LightGray,
        Vector2D::ScreenCenter().Subtract({-450, -200}), "PLayer 4");
}

void LobbyComp::addSel(
    std::vector<std::string> &list, const std::string &entitityName,
    Colors colors,
    Vector2D pos, const std::string &printedText
)
{
    auto &entitity = entity->_mgr.addEntity(entitityName);
    entitity.addComponent<TransformComp>(pos);
    ListSelector1 = &entitity
        .addComponent<ListSelectorComp>(
            list, printedText, colors);
}

void LobbyComp::init()
{
    Component::init();
    AddListSelector();
}

void LobbyComp::update()
{
    Component::update();
}

void LobbyComp::draw()
{
    Component::draw();
}
