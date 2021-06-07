/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include "raylib_encap/EAudio.hpp"

EAudio::EAudio()
{
    InitAudioDevice();
}

EAudio::~EAudio()
{
    CloseAudioDevice();
}

void EAudio::setVolume(float volume)
{
    SetMasterVolume(volume);
}
