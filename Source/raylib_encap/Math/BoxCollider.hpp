/*
** EPITECH PROJECT, 2024
** BoxCollider.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef BOXCOLLIDER_HPP
#define BOXCOLLIDER_HPP

#include <raylib_encap/ECube.hpp>

class BoxCollider {
public:
    BoxCollider();
    ~BoxCollider();
    static bool CheckBoxCollision(ECube cube1, ECube cube2);
private:
};

#endif //BOXCOLLIDER_HPP