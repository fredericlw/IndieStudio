/*
** EPITECH PROJECT, 2024
** Entity.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <raylib.h>
#include <AssetLoader.hpp>
#include "Component.hpp"
//#include "Manager.hpp"

class Entity {
protected:
    bool _active = true;
    bool _dontDesOnLoad = false;
    std::vector<std::unique_ptr<Component>> components;
    std::string _name;
public:
    Entity(std::string name, Manager &mgr);

    ~Entity()
    {
//        std::cout << "Destroying entity : " << _name << std::endl;
    }

    const std::string &getName() const;
    Manager &_mgr;
    AssetLoader *assets();
private:
    ComponentArray componentArray;
    ComponentBitSet componentBitSet;
    GroupBitSet groupBitSet;

public:
    void update();
    void draw();
    bool isActive() const;
    void destroy();
    bool GetDontDestroyOnLoad() const;
    void SetDontDestroyOnLoad(bool state);

    bool hasGroup(Group grp);
    void addGroup(Group grp);
    void delGroup(Group grp);

    template<typename T> bool hasComponent() const;

    template<typename T, typename... TArgs>
    T &addComponent(TArgs &&... mArgs)
    {
        T *comp(new T(std::forward<TArgs>(mArgs)...));
        comp->entity = this;
        std::unique_ptr<Component> uPtr(comp);
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