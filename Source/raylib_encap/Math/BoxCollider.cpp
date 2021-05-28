/*
** EPITECH PROJECT, 2024
** BoxCollider.cpp
** File description:
** Created by Leo Fabre
*/
#include <raylib.h>
#include "BoxCollider.hpp"

BoxCollider::BoxCollider()
{
}

BoxCollider::~BoxCollider()
{
}

bool BoxCollider::CheckBoxCollision(ECube cube1, ECube cube2)
{
//    if (CheckCollisionBoxes(
//        (BoundingBox){(Vector3){ playerPosition.x - playerSize.x/2,
//            playerPosition.y - playerSize.y/2,
//            playerPosition.z - playerSize.z/2 },
//            (Vector3){ playerPosition.x + playerSize.x/2,
//                playerPosition.y + playerSize.y/2,
//                playerPosition.z + playerSize.z/2 }},
//
//        (BoundingBox){(Vector3){ enemyBoxPos.x - enemyBoxSize.x/2,
//            enemyBoxPos.y - enemyBoxSize.y/2,
//            enemyBoxPos.z - enemyBoxSize.z/2 },
//            (Vector3){ enemyBoxPos.x + enemyBoxSize.x/2,
//                enemyBoxPos.y + enemyBoxSize.y/2,
//                enemyBoxPos.z + enemyBoxSize.z/2 }})) collision = true;
}
