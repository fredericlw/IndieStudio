/*
** EPITECH PROJECT, 2024
** EKeyboardInputModule.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef EKEYBOARDINPUTMODULE_HPP
#define EKEYBOARDINPUTMODULE_HPP
#include "Keys.h"
#include "AInputModule.hpp"
#include <map>

class EKeyboardInputModule : public AInputModule {
public:
    explicit EKeyboardInputModule(PlayerNum num);
    ~EKeyboardInputModule();
    bool GetButtonDown(Button btn) override;
    bool GetButtonUp(Button btn) override;
    bool GetButtonPressed(Button btn) override;
    bool GetButtonReleased(Button btn) override;
private:
    void SetP1Buttons();
    void SetP2Buttons();
    void SetP3Buttons();
    void SetP4Buttons();
};

#endif //EKEYBOARDINPUTMODULE_HPP