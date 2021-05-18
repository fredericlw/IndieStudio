/*
** EPITECH PROJECT, 2024
** main.cpp
** File description:
** Created by Leo Fabre
*/
#include <iostream>
#include <string>
#include "Bomberman.hpp"

int main(int ac, char **av)
{
    bool fullscreen = false;
    if (ac == 2) {
        std::string arg(av[1]);
        if (arg.compare("-f") == 0)
            fullscreen = true;
    }
    Bomberman game(fullscreen);
    return 0;
}
