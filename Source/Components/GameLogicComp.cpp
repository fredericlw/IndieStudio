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
#include <GUI/LobbyComp.hpp>
#include "GameLogicComp.hpp"
#include "Manager.hpp"
#include "Player.hpp"

void GameLogicComp::init()
{
    Component::init();
    auto &myEnt = entity->_mgr.addEntity("Player 1");
    myEnt.addComponent<TransformComp>(Vector3D(-10, -28, -40));
    myEnt.addComponent<BasicCubeComp>(Vector3D::One().Multiply(2));
    myEnt.addComponent<Player>(entity->getComponent<LobbyComp>().sel1,
        PlayerNum::PlayerOne, Blue);

    auto &myEnt2 = entity->_mgr.addEntity("Player 2");
    myEnt2.addComponent<TransformComp>(Vector3D(10, -28, -40));
    myEnt2.addComponent<BasicCubeComp>(Vector3D::One().Multiply(2));
    myEnt2.addComponent<Player>(entity->getComponent<LobbyComp>().sel2,
        PlayerNum::PlayerTwo, Green);


    auto &myEnt3 = entity->_mgr.addEntity("Player 3");
    myEnt3.addComponent<TransformComp>(Vector3D(-10, -28, -50));
    myEnt3.addComponent<BasicCubeComp>(Vector3D::One().Multiply(2));
    myEnt3.addComponent<Player>(entity->getComponent<LobbyComp>().sel3,
        PlayerNum::PlayerThree, Red);


    auto &myEnt4 = entity->_mgr.addEntity("Player 4");
    myEnt4.addComponent<TransformComp>(Vector3D(10, -28, -50));
    myEnt4.addComponent<BasicCubeComp>(Vector3D::One().Multiply(2));
    myEnt4.addComponent<Player>(entity->getComponent<LobbyComp>().sel4,
        PlayerNum::PlayerFour, LightGray);

}

void GameLogicComp::update()
{
    Component::update();
}

void GameLogicComp::draw()
{
    Component::draw();
}
