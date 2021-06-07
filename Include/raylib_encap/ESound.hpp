/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#ifndef ESOUND_HPP
#define ESOUND_HPP

#include <raylib.h>
#include <string>

class ESound {
public:
    ESound(std::string filename);
    ~ESound();
    void playSound();
    void stopSound();
    void pauseSound();
    void resumeSound();
private:
    Sound _sound;
};

#endif //ESOUND_HPP