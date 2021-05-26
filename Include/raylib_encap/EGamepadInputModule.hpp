/*
** EPITECH PROJECT, 2024
** EGamepadInputModule.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef EGAMEPADINPUTMODULE_HPP
#define EGAMEPADINPUTMODULE_HPP

#include <map>
#include <Keys.h>

class EGamepadInputModule {
public:
    EGamepadInputModule(
        int gamepad_nbr
    );
    ~EGamepadInputModule();
    bool GetButtonDown(Button btn);
    bool GetButtonUp(Button btn);
    bool GetButtonPressed(Button btn);
    bool GetButtonReleased(Button btn);
private:
    std::map<Button, int> KeyMap;
    int _gamepadNbr;
};

#endif //EGAMEPADINPUTMODULE_HPP