//
// Created by jupi on 28/05/2021.
//

#ifndef BOMBERMAN_LISTSELECTORCOMP_H
#define BOMBERMAN_LISTSELECTORCOMP_H

#include <raylib_encap/EText.hpp>
#include <3D/TransformComp.hpp>
#include <Keys.h>
#include "Component.hpp"


class ListSelectorComp : public Component {
public:
    ListSelectorComp();

    ListSelectorComp(const std::vector<std::string> &options, const std::string &label, Colors color);

    EInputType getSel() const;
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
    EText _label;
    int selIndex;
    std::vector<std::string> _options;
    TransformComp *_transform;
    bool _prevHover;
    bool _nextHover;
    Colors _color;
};


#endif //BOMBERMAN_LISTSELECTORCOMP_H
