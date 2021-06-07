/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#ifndef SOUNDEFFECTCOMP_HPP
#define SOUNDEFFECTCOMP_HPP

#include <Component.hpp>
#include <raylib_encap/ESound.hpp>
#include <string>

class SoundEffectComp : public Component, public ESound{
public:
    SoundEffectComp(std::string filepath);
    void init() override;
    void update() override;
    void draw() override;
};

#endif //SOUNDEFFECTCOMP_HPP