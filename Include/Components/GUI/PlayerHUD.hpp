/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by Achille Bourgault
*/

#ifndef STATUSINFOCOMP
#define STATUSINFOCOMP

#include <Component.hpp>
#include <functional>
#include <raylib_encap/ERect.hpp>
#include <raylib_encap/Math/Vector2D.hpp>
#include <Character/PlayerComp.hpp>
#include "TextComp.hpp"

class PlayerHUD : public Component {
    public:
    PlayerHUD(PlayerComp *player, Vector2D size);
    void init() override;
    void update() override;
    void draw() override;
    private:
    PlayerComp *_player;
    bool hovering;
    Vector2D size;
    ERect _backgroundRect;
    PowerUpType _lastPowerup;
    TransformComp *transform;
    Entity *_PowerUpDisplay;
    TextComp *_ScoreDisplay;
    ESprite *getPowerupSprite(PowerUpType type);
};
#endif