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
      wantToMove(true),
      wantPlaceBomb(false),
      stuckDirection(Button::Cancel)
{
    mapOrigin =
        manager.getEntByName("mapRoot")->getComponent<TransformComp>().position;
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
    auto res = wantPlaceBomb;

    if (btn != DropBomb)
        return false;
    if (wantPlaceBomb)
        wantPlaceBomb = false;
    return res;
}

bool EIAInputModule::GetButtonReleased(Button btn)
{
    return false;
}

bool EIAInputModule::IsStuck(Vector2D pos, Button direction)
{
    switch (direction) {
    case Left:
        if (isInWall(pos.x + 1, pos.y) && isInWall(pos.x, pos.y + 1) &&
            isInWall(pos.x, pos.y - 1)) {
            stuckDirection = direction;;
            return true;
        }
        break;
    case Right:
        if (isInWall(pos.x + 1, pos.y) && isInWall(pos.x, pos.y + 1) &&
            isInWall(pos.x, pos.y - 1)) {
            stuckDirection = direction;;
            return true;
        }
        break;
    case Up:
        if (isInWall(pos.x + 1, pos.y) && isInWall(pos.x -1 , pos.y) &&
            isInWall(pos.x, pos.y - 1)) {
            stuckDirection = direction;;
            return true;
        }
        break;
    case Down:
        if (isInWall(pos.x + 1, pos.y) && isInWall(pos.x -1 , pos.y) &&
            isInWall(pos.x, pos.y + 1)) {
            stuckDirection = direction;;
            return true;
        }
        break;
    case DropBomb:
        break;
    default:
        break;
    }
    return false;
}

bool EIAInputModule::isWarningByBomb()
{
    for (int y = 0; y < map.size(); y++) {
        for (int x = 0; x < map[x].size(); x++) {
            if (map[y][x] == 'B') {
            }
        }
    }
    return false;
}

void EIAInputModule::setDirection()
{
    auto bombs = manager.getEntitiesInGroup(GroupLabel::Bombs);
    for (auto &i : bombs) {
        auto cast = &i->getComponent<TransformComp>();
        map[tposz_To_mposy(cast->position.z)][
            tposx_To_mposx(cast->position.x)] = 'B';
    }


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

    bool stuck = IsStuck(myPos, directionPressed);

    if (stuck)
    {
        wantPlaceBomb = true;
    }

    for (auto &i : manager.getEntitiesInGroup(GroupLabel::Players)) {
        auto player = i->getComponent<PlayerComp>();
        auto pos = i->getComponent<TransformComp>().position;
        if (player.getPlayerNum() == _playerNum) {
            myPos =
                {(float) tposx_To_mposx(pos.x), (float) tposz_To_mposy(pos.z)};
        } else if (player.isAlive()) {
            AlivePLayers.emplace_back(
                tposx_To_mposx(pos.x), tposz_To_mposy(pos.z));
        }
    }

    int smallestTotal = 99;
    size_t smallestTotalIndex;
    int index = 0;
    for (auto iterator = AlivePLayers.begin();
        iterator != AlivePLayers.end(); ++iterator, ++index) {
        int total = abs(iterator->x - myPos.x) + abs(iterator->y - myPos.y);
        if (total < smallestTotal) {
            smallestTotalIndex = index;
            smallestTotal = total;
        }
    }

    closestPlayer = AlivePLayers[smallestTotalIndex];
    if (closestPlayer.y < myPos.y && !isInWall(myPos.x, myPos.y - 1)) {
        nextPos = {(size_t) myPos.x, (size_t) myPos.y - 1};
        directionPressed = Button::Up;
    } else if (closestPlayer.y > myPos.y && !isInWall(myPos.x, myPos.y + 1)) {
        nextPos = {(size_t) myPos.x, (size_t) myPos.y + 1};
        directionPressed = Button::Down;
    } else if (closestPlayer.x < myPos.x && !isInWall(myPos.x - 1, myPos.y)) {
        nextPos = {(size_t) myPos.x - 1, (size_t) myPos.y};
        directionPressed = Button::Left;
    } else if (closestPlayer.x > myPos.x && !isInWall(myPos.x + 1, myPos.y)) {
        nextPos = {(size_t) myPos.x + 1, (size_t) myPos.y};
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
    if (map[y][x] == 'W' || map[y][x] == 'o')
        return true;
    return false;
}
