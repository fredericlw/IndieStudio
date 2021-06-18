/*
** EPITECH PROJECT, 2024
** AInputModule.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef AINPUTMODULE_HPP
#define AINPUTMODULE_HPP

#include <map>
#include <Keys.h>

class AInputModule {
public:
    AInputModule();
    ~AInputModule();
    virtual bool GetButtonDown(Button btn) = 0;
    virtual bool GetButtonUp(Button btn) = 0;
    virtual bool GetButtonPressed(Button btn) = 0;
    virtual bool GetButtonReleased(Button btn) = 0;
    virtual void update() = 0;
protected:
    std::map<Button, int> KeyMap;
};

#endif //AINPUTMODULE_HPP