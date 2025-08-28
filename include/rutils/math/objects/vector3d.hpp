#ifndef VECTOR3D_GUARD
#define VECTOR3D_GUARD

#include <rutils/core/api.hpp>

namespace Recurring::Math
{
    struct Vector3D
    {
        float x, y, z;
        float length () const;
        Vector3D (float x, float y, float z);
        Vector3D ();

        Vector3D operator+ (const Vector3D& right_hand_side) const;
        Vector3D operator- (const Vector3D& right_hand_side) const;
        const Vector3D& operator= (const Vector3D& right_hand_size);

        bool operator== (const Vector3D& right_hand_side) const;
        bool operator!= (const Vector3D& right_hand_side) const;
        bool operator!() const;
    };
} // namespace Recurring::Math
#endif
