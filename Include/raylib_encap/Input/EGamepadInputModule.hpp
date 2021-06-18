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
#include "AInputModule.hpp"

class EGamepadInputModule : public AInputModule {
public:
    EGamepadInputModule(
        int gamepad_nbr
    );
    ~EGamepadInputModule();
    bool GetButtonDown(Button btn) override;
    bool GetButtonUp(Button btn) override;
    void update() override;
    bool GetButtonPressed(Button btn) override;
    bool GetButtonReleased(Button btn) override;
private:
    std::map<Button, int> KeyMap;
    int _gamepadNbr;
};

#endif //EGAMEPADINPUTMODULE_HPP