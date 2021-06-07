/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include "raylib_encap/EMusic.hpp"

EMusic::EMusic(std::string filename) : _music(LoadMusicStream(filename.c_str()))
{
}

EMusic::~EMusic()
{
    UnloadMusicStream(_music);
}

void EMusic::playMusic()
{
    PlayMusicStream(_music);
}

void EMusic::stopMusic()
{
    StopMusicStream(_music);
}

void EMusic::pauseMusic()
{
    PauseMusicStream(_music);
}

void EMusic::resumeMusic()
{
    ResumeMusicStream(_music);
}

bool EMusic::checkIfMusicIsPlaying()
{
    return IsMusicStreamPlaying(_music);
}
