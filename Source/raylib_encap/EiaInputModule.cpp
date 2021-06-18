/*
** EPITECH PROJECT, 2023
** bomberman
** File description:
** Created by Adrien Courbebaisse
*/
#include <EiaInputModule.hpp>
#include <3D/BasicCubeComp.hpp>
#include <Character/PlayerComp.hpp>

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
      manager(manager),
      wantToMove(true)
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

void EIAInputModule::update()
{
    setDirection();
}

EIAInputModule::~EIAInputModule()
{
}



bool EIAInputModule::GetButtonDown(Button btn)
{
    if (btn == directionPressed)
        return true;
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

void EIAInputModule::setDirection()
{
    //set obstacles
    auto obstacles = manager.getEntitiesInGroup(GroupLabel::Obstacles);
    for (auto &i : obstacles) {
        auto cast = &i->getComponent<TransformComp>();
        map[tposz_To_mposy(cast->position.z)][
            tposx_To_mposx(cast->position.x)] = 'o';
    }

    //find all alive players
    std::vector<Vector2D> AlivePLayers;
    Vector2D myPos;
    Vector2D closestPlayer;

    for (auto &i : manager.getEntitiesInGroup(GroupLabel::Players))
    {
        auto player = i->getComponent<PlayerComp>();
        auto pos = i->getComponent<TransformComp>().position;
        if (player.getPlayerNum() == _playerNum)
        {
            myPos = {(float)tposz_To_mposy(pos.x), (float)tposz_To_mposy(pos.y)};
        }
        else if (player.isAlive()) {
            AlivePLayers.emplace_back(
                tposz_To_mposy(pos.x), tposz_To_mposy(pos.y));
        }
    }

    int smallestTotal = 99;
    size_t smallestTotalIndex;
    int index = 0;
    for (auto iterator = AlivePLayers.begin();
        iterator != AlivePLayers.end(); ++iterator, ++index) {
        int total = abs(iterator->x - myPos.x) + abs(iterator->y - myPos.y);
        if (total < smallestTotal)
        {
            smallestTotalIndex = index;
            smallestTotal = total;
        }
    }

    closestPlayer = AlivePLayers[smallestTotalIndex];
    if (closestPlayer.y < myPos.y && !isInWall(myPos.x, myPos.y - 1)) {
        directionPressed = Button::Up;
    }  else if (closestPlayer.y > myPos.y && !isInWall(myPos.x, myPos.y + 1)) {
        directionPressed = Button::Down;
    } else if (closestPlayer.x < myPos.x && !isInWall(myPos.x - 1, myPos.y)) {
        directionPressed = Button::Left;
    } else if (closestPlayer.x > myPos.x && !isInWall(myPos.x + 1, myPos.y)) {
        directionPressed = Button::Right;
    }

    //rm obstaclces
    for (auto &i : obstacles) {
        auto cast = &i->getComponent<TransformComp>();
        map[tposz_To_mposy(cast->position.z)][
            tposx_To_mposx(cast->position.x)] = '0';
    }
}

bool EIAInputModule::isInWall(int x, int y)
{
    if (map[y][x] == 'W' || map [y][x] == 'o')
        return true;
    return false;
}
