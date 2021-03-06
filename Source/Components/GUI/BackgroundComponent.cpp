/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by Achille Bourgault
*/

#include "Component.hpp"
#include "raylib_encap/Window.hpp"
#include <GUI/BackgroundComponent.hpp>
#include "Entity.hpp"

void BackgroundComponent::init()
{
    Component::init();
    scrollA = 0.0f;
    scrollB = 0.0f;
    scrollC = 0.0f;
    scrollD = 0.0f;
    scrollE = 0.0f;
    if (Window::isFullScreen())
        scale = 5.25;
    entity->SetDontDestroyOnLoad(true);
}

void BackgroundComponent::update()
{
    scrollA -= 0.12f;
    scrollB -= 0.23f;
    scrollC -= 0.6f;
    scrollD -= 1.2f;
    scrollE -= 1.55f;

    if (scrollA <= -entity->assets()->MenuASprite.width*scale) scrollA = 0;
    if (scrollB <= -entity->assets()->MenuBSprite.width*scale) scrollB = 0;
    if (scrollC <= -entity->assets()->MenuCSprite.width*scale) scrollC = 0;
    if (scrollD <= -entity->assets()->MenuDSprite.width*scale) scrollD = 0;
    if (scrollE <= -entity->assets()->MenuESprite.width*scale) scrollE = 0;
    Component::update();
}

void BackgroundComponent::draw()
{
    Component::draw();
    entity->assets()->MenuASprite.drawEx(Vector2D {scrollA, 0}, 0.0f, scale);
    entity->assets()->MenuASprite.drawEx(Vector2D {entity->assets()->MenuASprite.width * scale + scrollA, 0}, 0.0f, scale);

    entity->assets()->MenuBSprite.drawEx(Vector2D {scrollB, 20}, 0.0f, scale);
    entity->assets()->MenuBSprite.drawEx(Vector2D {entity->assets()->MenuBSprite.width * scale + scrollB, 20}, 0.0f, scale);

    entity->assets()->MenuCSprite.drawEx(Vector2D {scrollC, 80}, 0.0f, scale);
    entity->assets()->MenuCSprite.drawEx(Vector2D {entity->assets()->MenuCSprite.width * scale + scrollC, 80}, 0.0f, scale);

    entity->assets()->MenuDSprite.drawEx(Vector2D {scrollD, 230}, 0.0f, scale);
    entity->assets()->MenuDSprite.drawEx(Vector2D {entity->assets()->MenuDSprite.width * scale + scrollD, 230}, 0.0f, scale);

    entity->assets()->MenuESprite.drawEx(Vector2D {scrollE, 250}, 0.0f, scale);
    entity->assets()->MenuESprite.drawEx(Vector2D {entity->assets()->MenuESprite.width * scale + scrollE, 250}, 0.0f, scale);
}
