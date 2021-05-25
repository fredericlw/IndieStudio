/*
** EPITECH PROJECT, 2024
** ButtonComp.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef BUTTONCOMP_HPP
#define BUTTONCOMP_HPP

#include <raylib_encap/Vector3D.hpp>
#include <raylib_encap/ERect.hpp>
#include "ECS/Component.hpp"
#include "TransformComp.hpp"
#include <functional>

class ButtonComp : public Component {
public:
    ButtonComp(const std::string &text,
        Vector2D size, Vector2D pos);
public:
    void update() override;
    void draw() override;
    void init() override;
    void AddEventFunc(
        const std::function<void()> &function);
private:
    bool hovering;
    std::string _text;
    Vector2D size;
    Vector3D pos;
    ERect _rect;
    TransformComp *transform;
    std::vector<std::function<void()>> EventFuncs;
};

#endif //BUTTONCOMP_HPP