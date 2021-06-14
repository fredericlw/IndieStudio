/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by Achille Bourgault
*/

#ifndef OPTIONCOMP
#define OPTIONCOMP

#include <Component.hpp>
#include <Manager.hpp>
#include <GUI/ListSelectorComp.hpp>

class OptionComp : public Component {
    public:
    OptionComp();
    void init() override;
    void update() override;
    void draw() override;
    void AddOptionSelector();
    private:
    ListSelectorComp *ListSelector1;
    ListSelectorComp *ListSelector2;
    ListSelectorComp *ListSelector3;
    ListSelectorComp *ListSelector4;
    ListSelectorComp *addSel(
        std::vector<std::string> &list, const std::string &entittyName,
        Colors colors, Vector2D pos, const std::string &printedText
    );
    void getSelection();
    EInputType sel1;
    EInputType sel2;
    EInputType sel3;
    EInputType sel4;
};

#endif