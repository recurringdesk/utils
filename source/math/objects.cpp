
#include <rutils/math/functions/basic.hpp>
#include <rutils/math/objects/vector2d.hpp>
#include <rutils/math/objects/vector3d.hpp>
#include <rutils/math/objects/vector4d.hpp>

namespace Recurring::Math
{
    //
    // Vector2D
    //

    bool
    Vector2D::operator!() const
    {
        return this->x == 0.0f && this->y == 0.0f;
    }

    bool
    Vector2D::operator== (const Vector2D& right_hand_side) const
    {
        return right_hand_side.x == this->x && right_hand_side.y == this->y;
    }

    bool
    Vector2D::operator!= (const Vector2D& right_hand_side) const
    {
        return right_hand_side.x != this->x || right_hand_side.y != this->y;
    }

    Vector2D::Vector2D ()
        : x (0.0f), y (0.0f)
    {
    }

    float
    Vector2D::length () const
    {
        return square_root ((x * x) + (y * y));
    }

    Vector2D::Vector2D (float x, float y) : x (x), y (y)
    {
    }

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

    const Vector2D&
    Vector2D::operator= (const Vector2D& right_hand_size)
    {
        x = right_hand_size.x;
        y = right_hand_size.y;
        return *this;
    }

    //
    // Vector3D
    //
    bool
    Vector3D::operator== (const Vector3D& right_hand_side) const
    {
        return this->x == right_hand_side.x && this->y == right_hand_side.y && this->z == right_hand_side.z;
    }

    bool
    Vector3D::operator!= (const Vector3D& right_hand_side) const
    {
        return this->x != right_hand_side.x || this->y != right_hand_side.y || this->z != right_hand_side.z;
    }

    bool
    Vector3D::operator!() const
    {
        return this->x == 0.0f && this->y == 0.0f && this->z == 0.0f;
    }

    float
    Vector3D::length () const
    {
        return square_root ((x * x) + (y * y) + (z * z));
    }

    Vector3D::Vector3D ()
        : x (0.0f), y (0.0f), z (0.0f)
    {
    }

    Vector3D::Vector3D (float x, float y, float z)
        : x (x), y (y), z (z)
    {
    }

    Vector3D
    Vector3D::operator+ (const Vector3D& right_hand_side) const
    {
        return Vector3D (x + right_hand_side.x, y + right_hand_side.y, z + right_hand_side.z);
    }

    Vector3D
    Vector3D::operator- (const Vector3D& right_hand_side) const
    {
        return Vector3D (x - right_hand_side.x, y - right_hand_side.y, z - right_hand_side.z);
    }

    //
    // Vector4D
    //

    /* 64::00 | 2025-08-28 01:54:20
    ---

    These methods have to be implemented:

    Vector4D operator+ (const Vector4D& right_hand_side) const;
    Vector4D operator- (const Vector4D& right_hand_side) const;
    const Vector4D& operator= (const Vector4D& right_hand_size);
    float length () const;
    */

    bool
    Vector4D::operator== (const Vector4D& right_hand_side) const
    {
        return this->x == right_hand_side.x && this->y == right_hand_side.y && this->z && right_hand_side.z && this->w == right_hand_side.w;
    }

    bool
    Vector4D::operator!= (const Vector4D& right_hand_side) const
    {
        return this->x != right_hand_side.x || this->y != right_hand_side.y || this->z || right_hand_side.z || this->w != right_hand_side.w;
    }

    bool
    Vector4D::operator!() const
    {
        return this->x == 0.0f && this->y == 0.0f && this->z == 0.0f && this->w == 0.0f;
    }

    Vector4D::Vector4D ()
        : x (0.0f), y (0.0f), z (0.0f), w (0.0f)
    {
    }

    Vector4D::Vector4D (float x, float y, float z, float w)
        : x (x), y (y), z (z), w (w)
    {
    }

} // namespace Recurring::Math
