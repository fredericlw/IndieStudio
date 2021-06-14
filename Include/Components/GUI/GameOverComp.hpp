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
    GameOverComp();
    void update() override;
    void draw() override;
    void init() override;
    void addQuitBtn();
    void addTitle();
    void DoGameOver();

private:
    TextComp *GoText;
    ButtonComp *GoButton;
};

#endif //BOMBERMAN_GAMEOVERCOMP_H