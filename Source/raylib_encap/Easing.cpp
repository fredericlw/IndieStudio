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

float Easing::LinearInOut(
    double currentTime, float start, float target, double duration
)
{
    return EaseLinearInOut(currentTime, start, target-start, duration);
}

float Easing::SineIn(
    double currentTime, float start, float target, double duration
)
{
    return EaseSineIn(currentTime, start, target-start, duration);
}


float Easing::SineOut(
    double currentTime, float start, float target, double duration
)
{
    return EaseSineOut(currentTime, start, target-start, duration);
}

float Easing::SineInOut(
    double currentTime, float start, float target, double duration
)
{
    return EaseSineInOut(currentTime, start, target-start, duration);
}
