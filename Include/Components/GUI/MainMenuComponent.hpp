/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by Achille Bourgault
*/

#ifndef bomberman_MainMenuComponent
#define bomberman_MainMenuComponent

#include <raylib_encap/ESprite.hpp>
#include "Component.hpp"

class MainMenuComponent : public Component {
    public:
    void init() override;
    void update() override;
    void draw() override;
};

#endif //BOMBERMAN_MAINMENUCOMPONENT_HPP
