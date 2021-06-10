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
    std::vector<std::string> listA = {"100", "90", "80", "70", "60", "50", "40",
        "30", "20", "10", "0"};
    std::vector<std::string> listB = {"Windowed", "FullScreen"};
    auto winSize = Window::GetWinSize();
    Vector2D size = Vector2D(50, 50);

    Vector2D posA = Vector2D{(winSize.x / 4) - (size.x / 2),
        (winSize.y / 2) - (size.y / 2)};
    Vector2D posB = Vector2D{(winSize.x / 4) * 3,
        (winSize.y / 2) - (size.y / 2)};

    ListSelector1 = addSel(listA, "Volume", Blue, posA, "Volume");
    ListSelector1->addEventFun([this](std::string selection) {
        auto value = std::stof(selection) / 100;
        entity->assets()->Volume = value;
    });
    ListSelector2 = addSel(listB, "Viewmode", Green, posB, "View mode");
    ListSelector2->addEventFun([](std::string selection) {
        Window::ToogleFullscreen();
    });
    if (Window::isFullScreen())
        ListSelector2->set_sel_index(1);
    else
        ListSelector2->set_sel_index(0);
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
    sel1 = ListSelector1->getSelInputType();
    sel2 = ListSelector2->getSelInputType();
    sel3 = ListSelector3->getSelInputType();
    sel4 = ListSelector4->getSelInputType();
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