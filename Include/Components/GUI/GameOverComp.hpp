//
// Created by jupi on 11/06/2021.
//

#ifndef BOMBERMAN_GAMEOVERCOMP_H
#define BOMBERMAN_GAMEOVERCOMP_H

#include <Component.hpp>

class GameOverComp : public Component {
    public:
    GameOverComp();
    void update() override;
    void draw() override;
    void init() override;
    void addQuitBtn();
    void addTitle();
};

#endif //BOMBERMAN_GAMEOVERCOMP_H