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
    std::vector<std::string> list = {"Keyboard", "Gamepad", "IA"};

    ListSelector1 =  addSel(
        list, "First PLayer", Blue,
        Vector2D::ScreenCenter().Subtract({450, -200}), "PLayer 1");
    ListSelector2 = addSel(
        list, "Second PLayer", Green,
        Vector2D::ScreenCenter().Subtract({150, -200}), "PLayer 2");
    ListSelector3 = addSel(
        list, "Third PLayer", Red,
        Vector2D::ScreenCenter().Subtract({-150, -200}), "PLayer 3");
    ListSelector4 = addSel(
        list, "Fourth PLayer", LightGray,
        Vector2D::ScreenCenter().Subtract({-450, -200}), "PLayer 4");
}

ListSelectorComp *LobbyComp::addSel(
    std::vector<std::string> &list, const std::string &entityName,
    Colors colors,
    Vector2D pos, const std::string &printedText
)
{
    auto &entitity = entity->_mgr.addEntity(entityName);
    entitity.addComponent<TransformComp>(pos);
    entitity.addGroup(GUI);
    //todo : Show player model on top of selector (in a new entity >> new modelcomp)
    return &entitity
        .addComponent<ListSelectorComp>(
            list, printedText, colors);
}

void LobbyComp::init()
{
    Component::init();
    entity->SetDontDestroyOnLoad(true);
    AddListSelector();
}

void LobbyComp::update()
{
    Component::update();
}

void LobbyComp::getSelection()
{
    sel1 = ListSelector1->getSel();
    sel2 = ListSelector2->getSel();
    sel3 = ListSelector3->getSel();
    sel4 = ListSelector4->getSel();
}

void LobbyComp::draw()
{
    Component::draw();
}
