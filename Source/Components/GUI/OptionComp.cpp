/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by Achille Bourgault
*/

#include <raylib_encap/Window.hpp>
#include "Components/GUI/OptionComp.hpp"
#include "Entity.hpp"

void OptionComp::AddOptionSelector()
{
    std::vector<std::string> listA = {"10", "20", "30", "40", "50", "60", "70",
        "80", "90", "100"};
    std::vector<std::string> listB = {"Windowed", "FullScreen"};
    auto winSize = Window::GetWinSize();
    Vector2D size = Vector2D(50, 50);

    Vector2D posA = Vector2D{(winSize.x / 4) - (size.x / 2),
        (winSize.y / 2) - (size.y / 2)};
    Vector2D posB = Vector2D{(winSize.x / 4) * 3,
        (winSize.y / 2) - (size.y / 2)};

    ListSelector1 = addSel(listA, "Volume", Blue, posA, "Volume");

    ListSelector2 = addSel(listB, "Viewmode", Green, posB, "View mode");
}

ListSelectorComp *OptionComp::addSel(std::vector<std::string> &list,
    const std::string &entitityName, Colors colors, Vector2D pos,
    const std::string &printedText)
{
    auto &entitity = entity->_mgr.addEntity(entitityName);
    entitity.addComponent<TransformComp>(pos);
    entitity.addGroup(GUI);
    return &entitity.addComponent<ListSelectorComp>(list, printedText, colors);
}

void OptionComp::getSelection()
{
    sel1 = ListSelector1->getSel();
    sel2 = ListSelector2->getSel();
    sel3 = ListSelector3->getSel();
    sel4 = ListSelector4->getSel();
}

OptionComp::OptionComp()
{
}

void OptionComp::init()
{
    Component::init();
    AddOptionSelector();
}

void OptionComp::update()
{
    Component::update();
}

void OptionComp::draw()
{
    Component::draw();
}