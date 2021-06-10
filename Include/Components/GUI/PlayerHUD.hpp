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
#include <Character/Player.hpp>

class PlayerHUD : public Component {
    public:
    PlayerHUD(Player *player, Vector2D size);
    void init() override;
    void update() override;
    void draw() override;
    private:
    Player *_player;
    bool hovering;
    Vector2D size;
    ERect _backgroundRect;
    PowerUpType _lastPowerup;
    TransformComp *transform;
    Entity *_PowerUpDisplay;
    std::vector<std::function<void()>> EventFuncs;
};
#endif