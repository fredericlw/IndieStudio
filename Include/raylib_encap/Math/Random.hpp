/*
** EPITECH PROJECT, 2024
** Random.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef RANDOM_HPP
#define RANDOM_HPP

#include "raylib.h"

class Random {
public:
    Random();
    ~Random();

    static int Range(int min, int max);

private:
};

#endif //RANDOM_HPP