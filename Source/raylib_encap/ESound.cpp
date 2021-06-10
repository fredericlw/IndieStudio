/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include "raylib_encap/ESound.hpp"

ESound::ESound(std::string filename) : _sound(LoadSound(filename.c_str()))
{
}

ESound::~ESound()
{
    UnloadSound(_sound);
}

void ESound::playSound(float volume)
{
    SetSoundVolume(_sound, volume);
    PlaySound(_sound);
}

void ESound::stopSound()
{
    StopSound(_sound);
}

void ESound::pauseSound()
{
    PauseSound(_sound);
}

void ESound::resumeSound()
{
    ResumeSound(_sound);
}

void ESound::setSoundVolume(float volume)
{
    SetSoundVolume(_sound, volume);
}

void ESound::Unload()
{
    UnloadSound(_sound);
}
