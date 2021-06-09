/*
** EPITECH PROJECT, 2024
** Easing.h
** File description:
** Created by Leo Fabre
*/
#ifndef EASING_HPP
#define EASING_HPP

#include <extras/easings.h>
#include <ctime>

class Easing {
public:
    static float LinearIn(
        double currentTime, float start, float target, double duration
    );
    static float LinearOut(
        double currentTime, float start, float target, double duration
    );
};

#endif //EASING_HPP