/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by Achille Bourgault
*/

#ifndef STATUSINFOCOMP
#define STATUSINFOCOMP

#include <Component.hpp>
#include <Player.hpp>
#include <raylib_encap/ERect.hpp>

class StatusInfoComp : public Component {
    public:
    StatusInfoComp(Player *player, ERect rect);
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