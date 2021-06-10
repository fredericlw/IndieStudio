/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#ifndef EMUSIC_HPP
#define EMUSIC_HPP

#include <raylib.h>
#include <string>

class EMusic {
public :
    EMusic(std::string filename);
    ~EMusic();
    void playMusic(float volume);
    void stopMusic();
    void pauseMusic();
    void resumeMusic();
    bool checkIfMusicIsPlaying();
    void setMusicVolume(float volume);
private:
    Music _music;
};

#endif //EMUSIC_HPP