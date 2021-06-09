/*
** EPITECH PROJECT, 2023
** bomberman
** File description:
** Created by Adrien Courbebaisse
*/
#include <AssetLoader.hpp>
#include "Components/GUI/LobbyComp.hpp"
#include "Entity.hpp"
#include "Manager.hpp"

void LobbyComp::AddListSelector()
{
    float distance = 3.5;
    auto pos = Vector3D(-5.25, -2.5, 7);
    std::vector<std::string> list = {"Keyboard", "Gamepad", "IA"};
    auto &assets = entity->_mgr.getEntByName("gamelogic")
        ->getComponent<AssetLoader>();
    auto *ent = &entity->_mgr.addEntity("modelDisp");
    ent->addGroup(GroupLabel::Players);
    ent->addComponent<TransformComp>(pos);
    ent->addComponent<ModelComp>(assets.PlayerModel, Blue);
    ListSelector1 = addSel(
        list, "First PLayer", Blue,
        Vector2D::ScreenCenter().Subtract({450, -200}), "Player 1");

    ent = &entity->_mgr.addEntity("modelDisp2");
    ent->addGroup(GroupLabel::Players);
    pos.x += distance;
    ent->addComponent<TransformComp>(pos);
    ent->addComponent<ModelComp>(assets.PlayerModel, Green);
    ListSelector2 = addSel(
        list, "Second PLayer", Green,
        Vector2D::ScreenCenter().Subtract({150, -200}), "Player 2");

    ent = &entity->_mgr.addEntity("modelDisp3");
    pos.x += distance;
    ent->addComponent<TransformComp>(pos);
    ent->addGroup(GroupLabel::Players);
    ent->addComponent<ModelComp>(assets.PlayerModel, Red);
    ListSelector3 = addSel(
        list, "Third PLayer", Red,
        Vector2D::ScreenCenter().Subtract({-150, -200}), "Player 3");

    ent = &entity->_mgr.addEntity("modelDisp4");
    pos.x += distance;
    ent->addComponent<TransformComp>(pos);
    ent->addGroup(GroupLabel::Players);
    ent->addComponent<ModelComp>(assets.PlayerModel, LightGray);
    ListSelector4 = addSel(
        list, "Fourth PLayer", LightGray,
        Vector2D::ScreenCenter().Subtract({-450, -200}), "Player 4");
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
