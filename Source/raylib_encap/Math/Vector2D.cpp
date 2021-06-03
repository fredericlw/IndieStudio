/*
** EPITECH PROJECT, 2024
** Vector3D.cpp
** File description:
** Created by Leo Fabre
*/
#include "raylib_encap/Math/Vector2D.hpp"
#include "raylib_encap/Math/Vector3D.hpp"

Vector2D::~Vector2D()
{
}

Vector2D::Vector2D(float x, float y)
    : Vector2({x, y})
{
}

Vector2D &Vector2D::Add(const Vector2D &vec)
{
    x += vec.x;
    y += vec.y;
    return *this;
}

Vector2D &Vector2D::Subtract(const Vector2D &vec)
{
    x -= vec.x;
    y -= vec.y;
    return *this;
}

Vector2D &Vector2D::Divide(const Vector2D &vec)
{
    x /= vec.x;
    y /= vec.y;
    return *this;
}

Vector2D &Vector2D::Multiply(const Vector2D &vec)
{
    x *= vec.x;
    y *= vec.y;
    return *this;
}

Vector2D &operator+(Vector2D &v1, const Vector2D &v2)
{
    return v1.Add(v2);
}

Vector2D &operator-(Vector2D &v1, const Vector2D &v2)
{
    return v1.Subtract(v2);
}

Vector2D &operator/(Vector2D &v1, const Vector2D &v2)
{
    return v1.Divide(v2);
}

Vector2D &operator*(Vector2D &v1, const Vector2D &v2)
{
    return v1.Multiply(v2);
}

Vector2D &Vector2D::operator+=(const Vector2D &vec)
{
    return Add(vec);
}

Vector2D &Vector2D::operator-=(const Vector2D &vec)
{
    return Subtract(vec);
}

Vector2D &Vector2D::operator/=(const Vector2D &vec)
{
    return Divide(vec);
}

Vector2D &Vector2D::operator*=(const Vector2D &vec)
{
    return Multiply(vec);
}

std::ostream &operator<<(std::ostream &os, const Vector2D &vec)
{
    os << "(" << vec.x << ";" << vec.y << ")";
    return os;
}

Vector2D::Vector2D(const Vector3D &vec) : Vector2({vec.x, vec.y})
{
}

bool Vector2D::operator==(const Vector2D &vec) const
{
    return x == vec.x && y == vec.y;
}

Vector2D::Vector2D() : Vector2({0,0})
{
}
