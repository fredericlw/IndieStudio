/*
** EPITECH PROJECT, 2023
** bomberman
** File description:
** Created by Adrien Courbebaisse
*/
#include "Components/3D/MeshCubeComp.hpp"
#include "Entity.hpp"
#include "Manager.hpp"

MeshCubeComp::MeshCubeComp(const Vector3D &size, std::string sprPath)
    : EMeshCube(size, sprPath)
{
}

void MeshCubeComp::draw()
{
    Component::draw();
    EMeshCube::draw(transform->position);
}

void MeshCubeComp::init()
{
    Component::init();
    transform = &entity->getComponent<TransformComp>();
    if (!transform)
        transform = &entity->addComponent<TransformComp>();

}
