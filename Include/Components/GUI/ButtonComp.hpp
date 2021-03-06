/*
** EPITECH PROJECT, 2024
** ButtonComp.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef BUTTONCOMP_HPP
#define BUTTONCOMP_HPP

#include <raylib_encap/Math/Vector3D.hpp>
#include <raylib_encap/ERect.hpp>
#include "ECS/Component.hpp"
#include "Components/3D/TransformComp.hpp"
#include <functional>
#include <raylib_encap/EText.hpp>

class ButtonComp : public Component {
public:
    ButtonComp(
        const std::string &text, Vector2D size, bool visible = true
    );
public:
    void update() override;
    void draw() override;
    void init() override;
    void AddEventFunc(
        const std::function<void()> &function);
private:
    bool hovering;
    bool Visible;
public:
    bool isVisible() const;
    void setVisible(bool visible);
private:
    EText _text;
    Vector2D size;
    ERect _rect;
    TransformComp *transform;
    std::vector<std::function<void()>> EventFuncs;
};

#endif //BUTTONCOMP_HPP