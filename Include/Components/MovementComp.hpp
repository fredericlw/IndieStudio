/*
** EPITECH PROJECT, 2024
** MovementComp.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef MOVEMENTCOMP_HPP
#define MOVEMENTCOMP_HPP

#include <raylib_encap/AInputModule.hpp>
#include "Components.h"

class MovementComp : public Component {
public:
    MovementComp(EInputType input_type, PlayerNum num);
    ~MovementComp();
private:
    TransformComp *transform;
    std::unique_ptr<AInputModule> _inputMod;
    void GenerateInputModule(EInputType type, PlayerNum num);
};

#endif //MOVEMENTCOMP_HPP