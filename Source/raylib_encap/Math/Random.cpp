/*
** EPITECH PROJECT, 2024
** Random.cpp
** File description:
** Created by Leo Fabre
*/
#include "raylib_encap/Math/Random.hpp"

Random::Random()
{
}

Random::~Random()
{
}

int Random::Range(int min, int max)
{
    return GetRandomValue(min, max);
}
