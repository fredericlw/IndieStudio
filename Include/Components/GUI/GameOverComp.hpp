//
// Created by jupi on 11/06/2021.
//

#ifndef BOMBERMAN_GAMEOVERCOMP_H
#define BOMBERMAN_GAMEOVERCOMP_H

#include <Component.hpp>
#include "GUI/ButtonComp.hpp"
#include "GUI/TextComp.hpp"

class GameOverComp : public Component {
    public:
    GameOverComp(std::array<bool, 4> playersAlive);
    void update() override;
    void draw() override;
    void init() override;
    void addQuitBtn();
    void addTitle();
    void DoGameOver();
    void DisplayScores();
private:
    TextComp *GoText;
    TextComp *GoPlayerWin;
    TextComp *GoWinner;
    ButtonComp *GoButton;
    std::array<bool, 4> _alive;
};

#endif //BOMBERMAN_GAMEOVERCOMP_H