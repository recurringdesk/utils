#include <recurring/math/functions/basic.hpp>
#include <recurring/math/objects/vector2d.hpp>
#include <recurring/math/objects/vector3d.hpp>

namespace Recurring::Math
{
    RLIB float
    Vector3D::length () const
    {
        return square_root ((x * x) + (y * y) + (z * z));
    }

    Vector3D::Vector3D (float x, float y, float z) : x (x), y (y), z (z) {}

    RLIB Vector3D
    Vector3D::operator+ (const Vector3D& right_hand_side) const
    {
        return Vector3D (x + right_hand_side.x, y + right_hand_side.y,
                         z + right_hand_side.z);
    }

    RLIB Vector3D
    Vector3D::operator- (const Vector3D& right_hand_side) const
    {
        return Vector3D (x - right_hand_side.x, y - right_hand_side.y,
                         z - right_hand_side.z);
    }

    RLIB float
    Vector2D::length () const
    {
        return square_root ((x * x) + (y * y));
    }

    RLIB
    Vector2D::Vector2D (float x, float y) : x (x), y (y)
    {
    }

    RLIB Vector2D
    Vector2D::operator+ (const Vector2D& right_hand_side) const
    {
        return Vector2D ((x + right_hand_side.x), (y + right_hand_side.y));
    }

    RLIB Vector2D
    Vector2D::operator- (const Vector2D& right_hand_side) const
    {
        return Vector2D ((x - right_hand_side.x), (y - right_hand_side.y));
    }
} // namespace Recurring::Math