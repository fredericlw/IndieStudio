/*
** EPITECH PROJECT, 2023
** bomberman
** File description:
** Created by Adrien Courbebaisse
*/
#include <EiaInputModule.hpp>
#include <3D/BasicCubeComp.hpp>

std::size_t EIAInputModule::tposx_To_mposx(float tposx)
{
    return ((tposx - mapOrigin.x) / 2) + 1;
}

std::size_t EIAInputModule::tposz_To_mposy(float tposz)
{
    return ((tposz - mapOrigin.z) / 2) + 1;
}

EIAInputModule::EIAInputModule(int gamepad_nbr, Manager &manager)
    : _playerNum(gamepad_nbr),
      manager(manager)
{
    mapOrigin = manager.getEntByName("mapRoot")->getComponent<TransformComp>().position;
    //2d map gen
    for (int i = 0; i < 11 + 2; i++) {
        std::vector<char> line;
        line.reserve(13 + 2);
        for (int j = 0; j < 13 + 2; ++j)
            line.push_back('0');
        map.push_back(line);
    }
    auto obstacles = manager.getEntitiesInGroup(GroupLabel::Obstacles);
    for (auto &i : obstacles) {
        auto cast = &i->getComponent<TransformComp>();
        map[tposz_To_mposy(cast->position.z)][
            tposx_To_mposx(cast->position.x)] = 'o';
    }

    auto walls = manager.getEntitiesInGroup(GroupLabel::Walls);
    for (auto &i : walls) {
        auto cast = &i->getComponent<TransformComp>();
        map[tposz_To_mposy(cast->position.z)][
            tposx_To_mposx(cast->position.x)] = 'W';
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
