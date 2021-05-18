/*
** EPITECH PROJECT, 2024
** Ecs.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef ECS_HPP
#define ECS_HPP

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>
class Component;
class Entity;

using ComponentID = std::size_t;

inline ComponentID getComponentTypeID();

template<typename T> inline ComponentID getComponentTypeID() noexcept
{
    static ComponentID typeID = getComponentTypeID();
    return typeID;
}

constexpr std::size_t maxComponents = 32;

using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component *, maxComponents>;

#endif //ECS_HPP