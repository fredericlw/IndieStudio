/*
** EPITECH PROJECT, 2023
** bomberman
** File description:
** Created by Adrien Courbebaisse
*/
#include "ECS/Manager.hpp"
#include "Components/Components.h"

void Manager::AddCubeZER()
{
    auto &monCUB = addEntity("Gro KUBE");
    monCUB.addComponent<TransformComp>(Vector3D(0,-20,-20));
    monCUB.addComponent<BasicCubeComp>(Vector3D::One().Multiply(2));
    monCUB.addComponent<MovementComp>(EInputType::Keyboard, PlayerNum::PlayerOne);
}
