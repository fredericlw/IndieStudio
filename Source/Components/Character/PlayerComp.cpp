/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by Achille Bourgault
*/

#include <Components/Logic/BombComp.hpp>
#include "Components/Character/PlayerComp.hpp"
#include <cmath>
#include <cfenv>
#include <Logic/GameLogicComp.hpp>
#include <BaseValues.h>
#include <GUI/PauseMenuComp.hpp>

PlayerComp::PlayerComp(
    EInputType e_type, PlayerNum player_num, Colors color
)
    : _eType(e_type),
      _playerNum(player_num),
      _color(color),
      _mc(nullptr),
      _model(nullptr),
      _powerUp(NONE),
      activeBombs(0),
      health(1),
      _maxBombs(1),
      _currentBombFire(BASE_BOMB_FIRE),
      score(0),
      _alive(true)
{
}

void PlayerComp::init()
{
    Component::init();
    _mc = &entity->addComponent<MovementComp>(_eType, _playerNum);
    _model = &entity
        ->addComponent<ModelComp>(entity->assets()->PlayerModel, _color);
    auto gamelogic = entity->_mgr.getEntByName("gamelogic");
    _pmc = &gamelogic->getComponent<PauseMenuComp>();

    //TODO: refactor to in IA move comp
    for (int i = 0; i < 11 + 2; i++)
    {
        std::vector<char> line;
        line.reserve(13 + 2);
        for (int j = 0; j < 13 + 2; ++j) {
            line.push_back('0');
        }
        map.push_back(line);

    }

}

void PlayerComp::update()
{
    Component::update();
    if (_eType != AI) {
        if (_mc->getInputModule()->GetButtonPressed(DropBomb)
            && (activeBombs < _maxBombs)
            && health > 0
            && !_pmc->isPaused()) {
            DoDropBomb();
        }
        if (_mc->getInputModule()->GetButtonPressed(Button::Cancel)) {
            _pmc->setIsPaused(true);
        }
    } else {
        IAupdate();
    }
}

void PlayerComp::draw()
{
    Component::draw();
}

void PlayerComp::DoDropBomb()
{
    activeBombs++;
    auto curPos = entity->getComponent<TransformComp>().position;
    auto &bombEnt = entity->_mgr.addEntity("bomb");
    bombEnt.addComponent<TransformComp>(
        getNearestBlockPos(curPos.Add({1, 0, 1})));
    bombEnt.addComponent<BombComp>(_color, this);
    bombEnt.addGroup(Bombs);
}

Colors PlayerComp::getColor() const
{
    return _color;
}

Vector3D PlayerComp::getNearestBlockPos(Vector3D pos)
{
    Vector3D res(pos);
    res.Add(Vector3D::One());
    res.y -= 1;
    std::fesetround(FE_TONEAREST);
    res.x = std::nearbyint(pos.x);
    res.z = std::nearbyint(pos.z);

    if (static_cast<int>(res.x) % 2 == 0) {
        if (res.x > pos.x) {
            res.x -= 1;
        } else {
            res.x += 1;
        }
    }
    if (static_cast<int>(res.z) % 2 == 0) {
        if (res.z > pos.z) {
            res.z -= 1;
        } else {
            res.z += 1;
        }
    }
    //todo : this is a quick and ugly (and not working) fix
    res.x -= 1;
    res.z -= 1;
    return res;
}

PowerUpType PlayerComp::getPowerUp() const
{
    return _powerUp;
}

void PlayerComp::setPowerUp(PowerUpType power_up, bool doAddScore)
{
    entity->assets()->PowerupPickUp.playSound(entity->assets()->Volume);
    StopPowerup(_powerUp);
    _powerUp = power_up;
    if (doAddScore) addScore(HIT_POWER_UP_SCORE);
    StartPowerup(power_up);
}

void PlayerComp::takeDamage()
{
    health--;
    std::cout << "PlayerComp hurt" << std::endl;
    if (health <= 0) {
        Die();
        return;
    }
    entity->assets()->PlayerHurt.playSound(entity->assets()->Volume);
}

void PlayerComp::Die()
{
    std::cout << "PLAYER DED :)" << std::endl;
    _alive = false;
    entity->assets()->PlayerDead.playSound(entity->assets()->Volume);
    entity->getComponent<ModelComp>().SetVisibility(false);
    _maxBombs = 0;
    _mc->SetActive(false);
}

bool PlayerComp::isAlive() const
{
    return _alive;
}

void PlayerComp::StopPowerup(PowerUpType type)
{
    switch (type) {
    case NONE:
    case ENUM_END:
    case SOFT_BLOCK_PASS:
        return;
    case FIREUP:
        if (_powerUp == FULLFIRE) return;
        _currentBombFire--;
        return;
    case FULLFIRE:
        _currentBombFire = BASE_BOMB_FIRE;
        return;
    case SKATE:
        _mc->setSpeed(BASESPEED);
        return;
    case BOMB_UP:
        _maxBombs--;
        return;
    }
}

void PlayerComp::StartPowerup(PowerUpType type)
{
    switch (type) {
    case NONE:
    case ENUM_END:
    case SOFT_BLOCK_PASS:
        return;
    case FIREUP:
        _currentBombFire++;
        if (_currentBombFire > MAX_BOMB_FIRE) _currentBombFire = MAX_BOMB_FIRE;
        return;
    case FULLFIRE:
        _currentBombFire = MAX_BOMB_FIRE;
        return;
    case SKATE:
        _mc->setSpeed(_mc->getSpeed() * SPEED_MULTIPLIER);
        return;
    case BOMB_UP:
        _maxBombs++;
        return;
    }
}

PlayerNum PlayerComp::getPlayerNum() const
{
    return _playerNum;
}

int PlayerComp::getScore() const
{
    return score;
}

void PlayerComp::addScore(int value)
{
    //TODO: if not playing, play value sound here
    score += value;
}

std::size_t tposx_Tom_posx(float tposx)
{
    return ((tposx + 12) / 2) + 1;

}

std::size_t tposz_To_mposy(float tposz)
{
    return ((tposz + 20) / 2)  + 1;

}

void PlayerComp::IAupdate()
{
    static bool first = true;
    if (first) {
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
        first = false;
    }
    /*auto mapEnt = entity->_mgr.getEntByName("mapRoot");
    auto mapComp = mapEnt->getComponent<
    MapComponent>();
    for (auto i : entity->_mgr.getEntitiesInGroup(GroupLabel::Walls))
    {

    }*/
}

void PlayerComp::setScore(int value)
{
    score = value;
}

void PlayerComp::killOnLoad()
{
    _alive = false;
    entity->getComponent<ModelComp>().SetVisibility(false);
    _maxBombs = 0;
    _mc->SetActive(false);
}
