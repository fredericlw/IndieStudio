/*
** EPITECH PROJECT, 2023
** bomberman
** File description:
** Created by Adrien Courbebaisse
*/
#ifndef EIAINPUTMODULE_HPP
#define EIAINPUTMODULE_HPP

#include <raylib_encap/Input/AInputModule.hpp>
#include "Entity.hpp"

class EIAInputModule : public AInputModule {
public:
    EIAInputModule(
        int gamepad_nbr, Entity *entity1
    );
    ~EIAInputModule();
    bool GetButtonDown(Button btn) override;
    bool GetButtonUp(Button btn) override;
    bool GetButtonPressed(Button btn) override;
    bool GetButtonReleased(Button btn) override;
private:
    size_t _playerNum;
    std::vector<std::shared_ptr<Entity>> otherPLayers;
    std::vector<std::vector<char>> map;
    Entity *entity;

};

#endif //EIAINPUTMODULE_HPP
