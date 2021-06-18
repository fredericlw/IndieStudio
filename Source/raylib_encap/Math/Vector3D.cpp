/*
** EPITECH PROJECT, 2024
** Vector3D.cpp
** File description:
** Created by Leo Fabre
*/
#include <cfenv>
#include <cmath>
#include "raylib_encap/Math/Vector3D.hpp"
#include "raylib_encap/Math/Vector2D.hpp"

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

Vector3D &Vector3D::Multiply(float factor)
{
    x *= factor;
    y *= factor;
    z *= factor;
    return *this;
}

Vector3D &Vector3D::Clamp(float maxMagnitude)
{
    if (x > maxMagnitude) x = maxMagnitude;
    if (y > maxMagnitude) y = maxMagnitude;
    if (z > maxMagnitude) z = maxMagnitude;
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

Vector3D &operator*(Vector3D &v1, float factor)
{
    return v1.Multiply(factor);
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

Vector3D &Vector3D::operator*=(float factor)
{
    return Multiply(factor);
}

std::ostream &operator<<(std::ostream &os, const Vector3D &vec)
{
    os << "(" << vec.x << ";" << vec.y << ";" << vec.z << ")";
    return os;
}

Vector3D::Vector3D() : Vector3({0, 0, 0})
{
}

Vector3D::Vector3D(const Vector2D& Vec) : Vector3({Vec.x, Vec.y, 0})
{
}

bool Vector3D::operator==(Vector3D other)
{
    return x == other.x && y == other.y && z == other.z;
}

bool Vector3D::operator!=(Vector3D other)
{
    return x != other.x || y != other.y || z != other.z;
}

Vector3D Vector3D::getNearestBlockPos(Vector3D pos)
{
    Vector3D res(pos);
    res.Add(Vector3D::One());
    res.y -= 1;
    std::fesetround(FE_TONEAREST);
    res.x = std::nearbyint(pos.x);
    res.z = std::nearbyint(pos.z);

    if (static_cast<int>(res.x) % 2 == 0) {
        if (res.x > pos.x) {
            res.x -= 1;
        } else {
            res.x += 1;
        }
    }
    if (static_cast<int>(res.z) % 2 == 0) {
        if (res.z > pos.z) {
            res.z -= 1;
        } else {
            res.z += 1;
        }
    }
    res.x -= 1;
    res.z -= 1;
    return res;
}