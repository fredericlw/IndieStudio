/*
** EPITECH PROJECT, 2023
** bomberman
** File description:
** Created by Adrien Courbebaisse
*/
#include <EiaInputModule.hpp>
#include <3D/BasicCubeComp.hpp>
#include "Manager.hpp"

std::size_t tposx_Tom_posx(float tposx)
{
    return ((tposx + 12) / 2) + 1;

}

std::size_t tposz_To_mposy(float tposz)
{
    return ((tposz + 20) / 2)  + 1;

}

EIAInputModule::EIAInputModule(int gamepad_nbr, Entity *entity1): _playerNum(gamepad_nbr), entity(entity1)
{
    //2d map gen
    for (int i = 0; i < 11 + 2; i++) {
        std::vector<char> line;
        line.reserve(13 + 2);
        for (int j = 0; j < 13 + 2; ++j)
            line.push_back('0');
        map.push_back(line);
    }
        auto obstacles = entity->_mgr.getEntitiesInGroup(GroupLabel::Obstacles);
        for (auto &i : obstacles) {
            auto cast = &i->getComponent<BasicCubeComp>();
            map[tposz_To_mposy(cast->getCube().getPos().z)][
                tposx_Tom_posx(cast->getCube().getPos().x)] = 'o';
        }

        auto walls = entity->_mgr.getEntitiesInGroup(GroupLabel::Walls);
        for (auto &i : walls) {
            auto cast = &i->getComponent<BasicCubeComp>();
            map[tposz_To_mposy(cast->getCube().getPos().z)][
                tposx_Tom_posx(cast->getCube().getPos().x)] = 'W';
        }

        for (auto i : map) {
            for (auto j : i)
                std::cout << j;
            std::cout << std::endl;
        }
}

EIAInputModule::~EIAInputModule()
{
}

bool EIAInputModule::GetButtonDown(Button btn)
{
    return false;
}

bool EIAInputModule::GetButtonUp(Button btn)
{
    return false;
}

bool EIAInputModule::GetButtonPressed(Button btn)
{
    return false;
}

bool EIAInputModule::GetButtonReleased(Button btn)
{
    return false;
}
