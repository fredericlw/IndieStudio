/*
** EPITECH PROJECT, 2023
** bomberman
** File description:
** Created by Adrien Courbebaisse
*/
#include "CubeCollider.hpp"

bool CubeCollider::CheckBoxOverLap(BoundingBox A, BoundingBox B)
{
    return CheckCollisionBoxes(A, B);
}

bool CubeCollider::CheckBoxOverLap(
    const ECube &A, const Vector3D &pos, const ECube &B
)
{
    BoundingBox a = {{
        pos.x - A.getSize().x / 2,
        pos.y - A.getSize().y / 2,
        pos.z - A.getSize().z / 2
    }, {
        pos.x + A.getSize().x / 2,
        pos.y + A.getSize().y / 2,
        pos.z + A.getSize().z / 2
    }
    };
    BoundingBox b = {{
        B.getPos().x - B.getSize().x / 2,
        B.getPos().y - B.getSize().y / 2,
        B.getPos().z - B.getSize().z / 2
    }, {
        B.getPos().x + B.getSize().x / 2,
        B.getPos().y + B.getSize().y / 2,
        B.getPos().z + B.getSize().z / 2
    }
    };
    return CheckCollisionBoxes(a, b);
}

bool CubeCollider::CheckBoxOverLap(const ECube &A, const ECube &B)
{
    BoundingBox a = {{
        A.getPos().x - A.getSize().x / 2,
        A.getPos().y - A.getSize().y / 2,
        A.getPos().z - A.getSize().z / 2
    }, {
        A.getPos().x + A.getSize().x / 2,
        A.getPos().y + A.getSize().y / 2,
        A.getPos().z + A.getSize().z / 2
    }
    };
    BoundingBox b = {{
        B.getPos().x - B.getSize().x / 2,
        B.getPos().y - B.getSize().y / 2,
        B.getPos().z - B.getSize().z / 2
    }, {
        B.getPos().x + B.getSize().x / 2,
        B.getPos().y + B.getSize().y / 2,
        B.getPos().z + B.getSize().z / 2
    }
    };
    return CheckCollisionBoxes(a, b);
}

bool CubeCollider::CheckBoxOverLap(const ECube &A, ModelComp &B)
{
    BoundingBox a = {{
        A.getPos().x - A.getSize().x / 2,
        A.getPos().y - A.getSize().y / 2,
        A.getPos().z - A.getSize().z / 2
    }, {
        A.getPos().x + A.getSize().x / 2,
        A.getPos().y + A.getSize().y / 2,
        A.getPos().z + A.getSize().z / 2
    }
    };
    BoundingBox b = GetMeshBoundingBox(B.getMesh());
    return false;
}
