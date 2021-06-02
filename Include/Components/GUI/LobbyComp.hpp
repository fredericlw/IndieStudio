/*
** EPITECH PROJECT, 2023
** bomberman
** File description:
** Created by Adrien Courbebaisse
*/
#ifndef LOBBYCOMP_HPP
#define LOBBYCOMP_HPP

#include "Component.hpp"

#include "ListSelectorComp.hpp"


class LobbyComp: public Component{
public:
    LobbyComp() = default;
    void draw() override;
    void init() override;
    void update() override;
public:
    ListSelectorComp *ListSelector1;
    ListSelectorComp *ListSelector2;
    ListSelectorComp *ListSelector3;
    ListSelectorComp *ListSelector4;
    void AddListSelector();
    void addSel(
        std::vector<std::string> &list, const std::string &entittyName,
        Colors colors, Vector2D pos, const std::string &printedText
    );
};

#endif //LOBBYCOMP_HPP
