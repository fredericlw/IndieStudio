/*
** EPITECH PROJECT, 2023
** bomberman
** File description:
** Created by Adrien Courbebaisse
*/
#ifndef EIAINPUTMODULE_HPP
#define EIAINPUTMODULE_HPP

#include <raylib_encap/Input/AInputModule.hpp>
#include "Entity.hpp"
#include "Manager.hpp"

struct Pos
{
    size_t x;
    size_t y;
};




class EIAInputModule : public AInputModule {
public:
    EIAInputModule(
        int gamepad_nbr, Manager &manager
    );
    ~EIAInputModule();
    bool GetButtonDown(Button btn) override;
    bool GetButtonUp(Button btn) override;
    bool GetButtonPressed(Button btn) override;
    bool GetButtonReleased(Button btn) override;
    void update() override;
private:
    size_t _playerNum;
    std::vector<Entity *> otherPLayers;
    std::vector<std::vector<char>> map;
    Manager &manager;
    Vector3D mapOrigin;
    size_t tposx_To_mposx(float tposx);
    size_t tposz_To_mposy(float tposz);
    void setDirection();
    Button directionPressed;
    Button lastDirection;
    bool wantToMove;
    bool wantPlaceBomb;
    bool isInWall(int x, int y);
    Pos nextPos;
    bool IsStuck(Vector2D d, Button button);
    bool isWarningByBomb();
    bool isWarningByBomb();
};

#endif //EIAINPUTMODULE_HPP
