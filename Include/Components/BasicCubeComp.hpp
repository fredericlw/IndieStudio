/*
** EPITECH PROJECT, 2024
** BasicCubeComp.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef BASICCUBECOMP_HPP
#define BASICCUBECOMP_HPP

#include <ECS/Component.hpp>

class BasicCubeComp : public Component {
public:
    BasicCubeComp();
    ~BasicCubeComp();
    void init() override;
    void update() override;
    void draw() override;
private:
};

#endif //BASICCUBECOMP_HPP