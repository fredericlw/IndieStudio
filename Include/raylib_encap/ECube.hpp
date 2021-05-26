/*
** EPITECH PROJECT, 2024
** ECube.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef ECUBE_HPP
#define ECUBE_HPP
#include "Colors.h"
class ECube {
public:
    ECube();
    ~ECube();
    void draw(
        Vector3D pos, Vector3D _size, Colors cubeColor, Colors wiresColor
    );
private:
};

#endif //ECUBE_HPP