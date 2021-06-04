/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by Achille Bourgault
*/

#ifndef STATUSINFOCOMP
#define STATUSINFOCOMP

#include <Component.hpp>
#include <Components/Character/Player.hpp>
#include <functional>
#include <raylib_encap/ERect.hpp>

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
    ERect _rect;
    TransformComp *transform;
    std::vector<std::function<void()>> EventFuncs;
};
#endif