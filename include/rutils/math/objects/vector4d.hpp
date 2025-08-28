#ifndef VECTOR4D_GUARD
#define VECTOR4D_GUARD

#include <rutils/core/api.hpp>

namespace Recurring::Math
{
    struct Vector4D
    {
        float x, y, z, w;
        float length () const;
        Vector4D (float x, float y, float z, float w);
        Vector4D ();

        Vector4D operator+ (const Vector4D& right_hand_side) const;
        Vector4D operator- (const Vector4D& right_hand_side) const;
        const Vector4D& operator= (const Vector4D& right_hand_size);

        bool operator== (const Vector4D& right_hand_side) const;
        bool operator!= (const Vector4D& right_hand_side) const;
        bool operator!() const;
    };
} // namespace Recurring::Math

#endif
