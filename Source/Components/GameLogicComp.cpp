/*
** EPITECH PROJECT, 2023
** bomberman
** File description:
** Created by Adrien Courbebaisse
*/
#include <3D/TransformComp.hpp>
#include <3D/ModelComp.hpp>
#include <3D/BasicCubeComp.hpp>
#include <Character/MovementComp.hpp>
#include "GameLogicComp.hpp"
#include "Manager.hpp"

void GameLogicComp::init()
{
    Component::init();
    auto &myEnt = entity->_mgr.addEntity("Player 1");
    myEnt.addComponent<TransformComp>(Vector3D(-10, -28, -40));
    myEnt.addComponent<ModelComp>("./rsc/Models/mrfixit.iqm", Blue, 0.77);
    myEnt.getComponent<ModelComp>().rotate({90, 0, 0});
    myEnt.addComponent<BasicCubeComp>(Vector3D::One().Multiply(2));
    myEnt.addComponent<MovementComp>(entity->getComponent<LobbyComp>().sel1,
        PlayerNum::PlayerOne);

    auto &myEnt2 = entity->_mgr.addEntity("Player 2");
    myEnt2.addComponent<TransformComp>(Vector3D(10, -28, -40));
    myEnt2.addComponent<ModelComp>("./rsc/Models/mrfixit.iqm", Green, 0.77);
    myEnt2.getComponent<ModelComp>().rotate({90, 0, 0});
    myEnt2.addComponent<BasicCubeComp>(Vector3D::One().Multiply(2));
    myEnt2.addComponent<MovementComp>(entity->getComponent<LobbyComp>().sel1,
        PlayerNum::PlayerTwo);

    auto &myEnt3 = entity->_mgr.addEntity("Player 3");
    myEnt3.addComponent<TransformComp>(Vector3D(-10, -28, -50));
    myEnt3.addComponent<ModelComp>("./rsc/Models/mrfixit.iqm", Red, 0.77);
    myEnt3.getComponent<ModelComp>().rotate({90, 0, 0});
    myEnt3.addComponent<BasicCubeComp>(Vector3D::One().Multiply(2));
    myEnt3.addComponent<MovementComp>(entity->getComponent<LobbyComp>().sel1,
        PlayerNum::PlayerThree);

    auto &myEnt4 = entity->_mgr.addEntity("Player 4");
    myEnt4.addComponent<TransformComp>(Vector3D(10, -28, -50));
    myEnt4.addComponent<ModelComp>("./rsc/Models/mrfixit.iqm", LightGray, 0.77);
    myEnt4.getComponent<ModelComp>().rotate({90, 0, 0});
    myEnt4.addComponent<BasicCubeComp>(Vector3D::One().Multiply(2));
    myEnt4.addComponent<MovementComp>(entity->getComponent<LobbyComp>().sel1,
        PlayerNum::PlayerFour);
}

void GameLogicComp::update()
{
    Component::update();
}

void GameLogicComp::draw()
{
    Component::draw();
}
