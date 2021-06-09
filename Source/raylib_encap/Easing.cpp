/*
** EPITECH PROJECT, 2024
** Easing.cpp
** File description:
** Created by Leo Fabre
*/
#include <raylib_encap/Easing.hpp>

float Easing::LinearIn(
    double currentTime, float start, float target, double duration
)
{
    return EaseLinearIn(currentTime, start, target-start, duration);
}

float Easing::LinearOut(
    double currentTime, float start, float target, double duration
)
{
    return EaseLinearOut(currentTime, start, target-start, duration);
}
