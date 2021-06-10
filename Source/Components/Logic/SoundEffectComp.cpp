/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include "Components/Logic/SoundEffectComp.hpp"

void SoundEffectComp::init()
{
    Component::init();
}

void SoundEffectComp::update()
{
    Component::update();
}

void SoundEffectComp::draw()
{
    Component::draw();
    ESound::playSound(0);
}

SoundEffectComp::SoundEffectComp(std::string filepath) : ESound(filepath)
{
}