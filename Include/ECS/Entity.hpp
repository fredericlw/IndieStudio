/*
** EPITECH PROJECT, 2024
** Entity.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef ENTITY_HPP
#define ENTITY_HPP
#include "Component.hpp"
class Entity {
private:
    bool active = true;
    std::vector<std::unique_ptr<Component>> components;

    ComponentArray componentArray;
    ComponentBitSet componentBitSet;
public:
    void update();

    void draw();

    bool isActive() const
    {
        return active;
    }

    void destroy();

    template<typename T> bool hasComponent() const;

    template<typename T, typename... TArgs>
    T &addComponent(TArgs &&... mArgs)
    {
        T *comp(new T(std::forward<TArgs>(mArgs)...));
        comp->entity = this;
        std::unique_ptr<Component> uPtr
            (comp);
        components.emplace_back(std::move(uPtr));
        componentArray[getComponentTypeID<T>()] = comp;
        componentBitSet[getComponentTypeID<T>()] = true;
        comp->init();
        return *comp;
    }

    template<typename T> T &getComponent() const
    {
        auto ptr(componentArray[getComponentTypeID<T>()]);
        return *static_cast<T *>(ptr);
    }
};

#endif //ENTITY_HPP