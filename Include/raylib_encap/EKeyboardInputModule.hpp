/*
** EPITECH PROJECT, 2024
** EKeyboardInputModule.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef EKEYBOARDINPUTMODULE_HPP
#define EKEYBOARDINPUTMODULE_HPP

#include <vector>
#include <map>

class EKeyboardInputModule {
public:
    enum Button {
        Accept,
        Cancel,
        Left,
        Right,
        Up,
        Down,
        DropBomb
    };
    enum PlayerNum {
        PlayerOne,
        PlayerTwo,
        PlayerThree,
        PlayerFour
    };
    explicit EKeyboardInputModule(PlayerNum num);
    ~EKeyboardInputModule();
    bool GetButtonDown(Button btn);
    bool GetButtonUp(Button btn);
    bool GetButtonPressed(Button btn);
    bool GetButtonReleased(Button btn);
private:
    std::map<Button, int> KeyMap;
    void SetP1Buttons();
    void SetP2Buttons();
    void SetP3Buttons();
    void SetP4Buttons();
};

#endif //EKEYBOARDINPUTMODULE_HPP