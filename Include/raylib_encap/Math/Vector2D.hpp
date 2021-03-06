/*
** EPITECH PROJECT, 2024
** Vector2D.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef Vector2D_HPP
#define Vector2D_HPP

#include <raylib.h>
#include <ostream>
class Vector3D;

class Vector2D : public Vector2 {
public:
    Vector2D();
    Vector2D(float x, float y);
    explicit Vector2D(const Vector3D &vec);
    Vector2D(Vector2 vec) : Vector2({vec.x, vec.y}){}

    ~Vector2D();

    //region Static values
    static Vector2D Zero()
    {
        return Vector2D(0, 0);
    }

    static Vector2D One()
    {
        return Vector2D(1, 1);
    }

    static Vector2D Up()
    {
        return Vector2D(0, -1);
    }

    static Vector2D Right()
    {
        return Vector2D(1, 0);
    }

    static Vector2D ScreenCenter()
    {
        return Vector2D((float) GetScreenWidth() / 2,
            (float) GetScreenHeight() / 2);
    }
    //endregion

    //region Operators

    Vector2D &Add(const Vector2D &vec);
    Vector2D &Subtract(const Vector2D &vec);
    Vector2D &Divide(const Vector2D &vec);
    Vector2D &Multiply(const Vector2D &vec);

    friend Vector2D &operator+(Vector2D &v1, const Vector2D &v2);
    friend Vector2D &operator-(Vector2D &v1, const Vector2D &v2);
    friend Vector2D &operator/(Vector2D &v1, const Vector2D &v2);
    friend Vector2D &operator*(Vector2D &v1, const Vector2D &v2);

    Vector2D &operator+=(const Vector2D &vec);
    Vector2D &operator-=(const Vector2D &vec);
    Vector2D &operator/=(const Vector2D &vec);
    Vector2D &operator*=(const Vector2D &vec);

    bool operator==(const Vector2D &vec) const;

    friend std::ostream &operator<<(std::ostream &os, const Vector2D &d);
    //endregion

};

#endif //Vector2D_HPP