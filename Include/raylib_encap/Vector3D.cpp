/*
** EPITECH PROJECT, 2024
** Vector3D.cpp
** File description:
** Created by Leo Fabre
*/
#include "Vector3D.hpp"
#include "Vector2D.hpp"

Vector3D::~Vector3D()
{
}

Vector3D::Vector3D(float x, float y, float z)
    : Vector3({x, y, z})
{
}

Vector3D &Vector3D::Add(const Vector3D &vec)
{
    x += vec.x;
    y += vec.y;
    z += vec.z;
    return *this;
}

Vector3D &Vector3D::Subtract(const Vector3D &vec)
{
    x -= vec.x;
    y -= vec.y;
    z -= vec.z;
    return *this;
}

Vector3D &Vector3D::Divide(const Vector3D &vec)
{
    x /= vec.x;
    y /= vec.y;
    z /= vec.z;
    return *this;
}

Vector3D &Vector3D::Multiply(const Vector3D &vec)
{
    x *= vec.x;
    y *= vec.y;
    z *= vec.z;
    return *this;
}

Vector3D &operator+(Vector3D &v1, const Vector3D &v2)
{
    return v1.Add(v2);
}

Vector3D &operator-(Vector3D &v1, const Vector3D &v2)
{
    return v1.Subtract(v2);
}

Vector3D &operator/(Vector3D &v1, const Vector3D &v2)
{
    return v1.Divide(v2);
}

Vector3D &operator*(Vector3D &v1, const Vector3D &v2)
{
    return v1.Multiply(v2);
}

Vector3D &Vector3D::operator+=(const Vector3D &vec)
{
    return Add(vec);
}

Vector3D &Vector3D::operator-=(const Vector3D &vec)
{
    return Subtract(vec);
}

Vector3D &Vector3D::operator/=(const Vector3D &vec)
{
    return Divide(vec);
}

Vector3D &Vector3D::operator*=(const Vector3D &vec)
{
    return Multiply(vec);
}

std::ostream &operator<<(std::ostream &os, const Vector3D &vec)
{
    os << "(" << vec.x << ";" << vec.y << ";" << vec.z << ")";
    return os;
}

Vector3D::Vector3D(const Vector2D& Vec) : Vector3({Vec.x, Vec.y, 0})
{
}

