/*
** EPITECH PROJECT, 2024
** BasicCubeComp.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef BASICCUBECOMP_HPP
#define BASICCUBECOMP_HPP

#include <ECS/Component.hpp>
#include <raylib_encap/Math/Vector3D.hpp>
#include <raylib_encap/ECube.hpp>
#include "TransformComp.hpp"

class BasicCubeComp : public Component {
public:
    explicit BasicCubeComp(Vector3D size, Colors cubeCol = Red, Colors wireCol = RayWhite, const Vector3D& offset = Vector3D::Zero());
    explicit BasicCubeComp(int size, Colors cubeCol = Red, Colors wireCol = RayWhite, const Vector3D& offset = Vector3D::Zero());
    explicit BasicCubeComp(float size, Colors cubeCol = Red, Colors wireCol = RayWhite, const Vector3D& offset = Vector3D::Zero());
    ~BasicCubeComp();
    void init() override;
    void update() override;
    void draw() override;
    const ECube &getCube() const;
    void stickCube(Vector3D &nextpos, ECube const &colisionCube);
    Vector3D _size;
    Colors _cubeCol;
    Colors _wireCol;
    bool shouldDraw;
private:
    TransformComp *transform;
    ECube _cube;
    Vector3D _offset;
    void stickCube(Vector3D &nextpos, const Mesh &colisionMesh);
};

#endif //BASICCUBECOMP_HPP