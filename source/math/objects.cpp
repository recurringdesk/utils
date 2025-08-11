#include <recurring/math/functions/square_root.hpp>
#include <recurring/math/objects/vector2d.hpp>
#include <recurring/math/objects/vector3d.hpp>

namespace Recurring::Math
{
    float
    Vector3D::length () const
    {
        return square_root ((x * x) + (y * y) + (z * z));
    }

    Vector3D::Vector3D (float x, float y, float z) : x (x), y (y), z (z) {}

    Vector3D
    Vector3D::operator+ (const Vector3D& right_hand_side) const
    {
        return Vector3D (x + right_hand_side.x, y + right_hand_side.y,
                         z + right_hand_side.z);
    }

    Vector3D
    Vector3D::operator- (const Vector3D& right_hand_side) const
    {
        return Vector3D (x - right_hand_side.x, y - right_hand_side.y,
                         z - right_hand_side.z);
    }

    float
    Vector2D::length () const
    {
        return square_root ((x * x) + (y * y));
    }

    Vector2D::Vector2D (float x, float y) : x (x), y (y) {}

    Vector2D
    Vector2D::operator+ (const Vector2D& right_hand_side) const
    {
        return Vector2D ((x + right_hand_side.x), (y + right_hand_side.y));
    }

    Vector2D
    Vector2D::operator- (const Vector2D& right_hand_side) const
    {
        return Vector2D ((x - right_hand_side.x), (y - right_hand_side.y));
    }
} // namespace Recurring::Math