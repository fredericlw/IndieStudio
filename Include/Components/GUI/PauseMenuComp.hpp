/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#ifndef PAUSEMENUCOMP_HPP
#define PAUSEMENUCOMP_HPP

#include "Component.hpp"
#include "ButtonComp.hpp"

class PauseMenuComp : public Component{
public:
    PauseMenuComp();
    void init() override;
    void update() override;
    void draw() override;
    void setIsPaused(bool is_paused);
    bool isPaused() const;
    void MenuButton();
    void ExitButton();
private:
    bool _isPaused;
    ButtonComp *resume_btn;
    ButtonComp *Menu_btn;
    ButtonComp *Exit_Btn;
};

#endif //PAUSEMENUCOMP_HPP