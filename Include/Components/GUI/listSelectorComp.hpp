//
// Created by jupi on 28/05/2021.
//

#ifndef BOMBERMAN_LISTSELECTORCOMP_H
#define BOMBERMAN_LISTSELECTORCOMP_H

#include "Component.hpp"
#include "Components.h"


class listSelectorComp : public Component {
public:
    listSelectorComp();

    listSelectorComp(const std::vector<std::string> &options);

private:
public:
    void init() override;

    void update() override;

    void draw() override;

private:
    ERect _prevRect;
    ERect _nextRect;
    EText _Select;
    EText _prevText;
    EText _nextText;
    int selIndex;
    std::vector<std::string> _options;
    TransformComp *_transform;
    bool _prevHover;
    bool _nextHover;
};


#endif //BOMBERMAN_LISTSELECTORCOMP_H
