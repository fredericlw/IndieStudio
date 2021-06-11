/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by Achille Bourgault
*/

#ifndef bomberman_BackgroundComponent
#define bomberman_BackgroundComponent

#include <raylib_encap/ESprite.hpp>
#include "Component.hpp"

class BackgroundComponent : public Component {
    public:
    void init() override;
    void update() override;
    void draw() override;
    private:
    float scrollA;
    float scrollB;
    float scrollC;
    float scrollD;
    float scrollE;
    float scale = 3.25f;
};

#endif //BOMBERMAN_BACKGROUNDCOMPONENT_HPP
