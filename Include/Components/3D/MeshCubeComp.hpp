/*
** EPITECH PROJECT, 2023
** bomberman
** File description:
** Created by Adrien Courbebaisse
*/
#ifndef MESHCUBECOMP_HPP
#define MESHCUBECOMP_HPP

#include <raylib_encap/EMeshCube.hpp>
#include "Component.hpp"
#include "TransformComp.hpp"

class MeshCubeComp : public Component, public EMeshCube{
public:
    MeshCubeComp(const Vector3D &size, std::string sprPath);
    void draw() override;
    void init() override;
private:
    TransformComp *transform;
};

#endif //MESHCUBECOMP_HPP
