/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#ifndef EAUDIO_HPP
#define EAUDIO_HPP

#include <raylib.h>

class EAudio {
public:
    EAudio();
    ~EAudio();
    void setVolume(float volume);
};

#endif //EAUDIO_HPP