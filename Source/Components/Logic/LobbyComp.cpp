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

void LobbyComp::AddListSelectors()
{
    float modelDistance = 3.5;
    auto modelPos = Vector3D(-5.25, -2.5, 7);
    std::vector<std::string> list = {"Keyboard", "Gamepad", "IA"};
    auto *ent = &entity->_mgr.addEntity("modelDisp1");
    ent->addGroup(GroupLabel::Players);
    ent->addComponent<TransformComp>(modelPos);
//    ent->addComponent<ModelComp>(entity->assets()->PlayerModel, Blue);
    ent->addComponent<FramesModel>(entity->assets()->playerWalking, entity->assets()->PlayerModel, Blue);

    ListSelector1 = addSel(
        list, "First PLayer", Blue,
        Vector2D::ScreenCenter().Subtract({450, -200}), "Player 1");

    ent = &entity->_mgr.addEntity("modelDisp2");
    ent->addGroup(GroupLabel::Players);
    modelPos.x += modelDistance;
    ent->addComponent<TransformComp>(modelPos);
//    ent->addComponent<ModelComp>(entity->assets()->PlayerModel, Green);
    ent->addComponent<FramesModel>(entity->assets()->playerWalking, entity->assets()->PlayerModel, Green);

    ListSelector2 = addSel(
        list, "Second PLayer", Green,
        Vector2D::ScreenCenter().Subtract({150, -200}), "Player 2");

    ent = &entity->_mgr.addEntity("modelDisp3");
    modelPos.x += modelDistance;
    ent->addComponent<TransformComp>(modelPos);
    ent->addGroup(GroupLabel::Players);
//    ent->addComponent<ModelComp>(entity->assets()->PlayerModel, Red);
    ent->addComponent<FramesModel>(entity->assets()->playerWalking, entity->assets()->PlayerModel,Red);
    ListSelector3 = addSel(
        list, "Third PLayer", Red,
        Vector2D::ScreenCenter().Subtract({-150, -200}), "Player 3");

    ent = &entity->_mgr.addEntity("modelDisp4");
    modelPos.x += modelDistance;
    ent->addComponent<TransformComp>(modelPos);
    ent->addGroup(GroupLabel::Players);
//    ent->addComponent<ModelComp>(entity->assets()->PlayerModel, LightGray);
    ent->addComponent<FramesModel>(entity->assets()->playerWalking, entity->assets()->PlayerModel,LightGray);
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
    AddListSelectors();
}

void LobbyComp::update()
{
    Component::update();
}

void LobbyComp::refreshSelections()
{
    sel1 = ListSelector1->getSelInputType();
    sel2 = ListSelector2->getSelInputType();
    sel3 = ListSelector3->getSelInputType();
    sel4 = ListSelector4->getSelInputType();
}

void LobbyComp::draw()
{
    Component::draw();
}
