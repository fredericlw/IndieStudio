/*
** EPITECH PROJECT, 2024
** ECube.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef ECUBE_HPP
#define ECUBE_HPP

#include <raylib_encap/Math/Vector3D.hpp>
#include "Colors.h"

class ECube {
public:
    ECube();
    ECube(const Vector3D& pos, const Vector3D& size);
    ECube(BoundingBox box);
    ~ECube();
    void draw(
        const Vector3D& pos, const Vector3D& size, Colors cubeColor, Colors wiresColor
    );
private:
    Vector3D _pos;
public:
    const Vector3D &getPos() const;
    const Vector3D &getSize() const;
    void setPos(const Vector3D &pos);
private:
    Vector3D _size;
public:
    void setSize(const Vector3D &size);
};

#endif //ECUBE_HPP