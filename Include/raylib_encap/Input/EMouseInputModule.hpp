/*
** EPITECH PROJECT, 2024
** EMouseInputModule.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef EMOUSEINPUTMODULE_HPP
#define EMOUSEINPUTMODULE_HPP

#include <Keys.h>
#include "raylib_encap/Math/Vector2D.hpp"

class EMouseInputModule {
public:
    EMouseInputModule();
    ~EMouseInputModule();
    static bool GetButtonDown(EMouseButton btn);
    static bool GetButtonUp(EMouseButton btn);
    static bool GetButtonPressed(EMouseButton btn);
    static bool GetButtonReleased(EMouseButton btn);
    static Vector2D GetMousePos();
private:
};

#endif //EMOUSEINPUTMODULE_HPP