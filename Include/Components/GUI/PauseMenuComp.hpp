/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#ifndef PAUSEMENUCOMP_HPP
#define PAUSEMENUCOMP_HPP

#include "Components.h"

class PauseMenuComp : public Component{
public:
    PauseMenuComp();
    void init() override;
    void update() override;
    void draw() override;
    void setIsPaused(bool is_paused);
    bool isIsPaused() const;
private:
    bool _isPaused;
    ButtonComp *resume_btn;
};

#endif //PAUSEMENUCOMP_HPP