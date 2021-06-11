//
// Created by jupi on 11/06/2021.
//

#ifndef BOMBERMAN_GAMEOVERCOMP_H
#define BOMBERMAN_GAMEOVERCOMP_H


class GameOverComp {
    public:
    GameOverComp();
    void update() override;
    void draw() override;
    void init() override;
    void addBackGameOverSceneButton();
};


#endif //BOMBERMAN_GAMEOVERCOMP_H
