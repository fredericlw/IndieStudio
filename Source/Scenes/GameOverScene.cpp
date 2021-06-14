/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by daniyel gouasmi
*/

#include "Manager.hpp"
#include <ECS/Manager.hpp>
#include <Components/3D/BasicCubeComp.hpp>
#include <raylib_encap/Math/Vector2D.hpp>
#include <raylib_encap/Window.hpp>
#include <GUI/GameOverComp.hpp>
#include "Components/Components.h"
#include "Components/GUI/OptionComp.hpp"

void Manager::loadGameOverScene() {
    std::cout << "Game Over" << std::endl;
//    QuitGameOverSceneButton();
    auto &ent = addEntity("gameOver");
      ent.addComponent<GameOverComp>(getEntByName("gamelogic")->getComponent<GameLogicComp>().playerScores);
    //TODO : use PLAYER SCORE THEN DESTROY
}