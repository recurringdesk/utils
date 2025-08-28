#ifndef VECTOR2D_GUARD
#define VECTOR2D_GUARD

#include <rutils/core/api.hpp>

namespace Recurring::Math
{
    struct Vector2D
    {
        float x, y;
        float length () const;
        Vector2D (float x, float y);
        Vector2D ();

        Vector2D operator+ (const Vector2D& right_hand_side) const;
        Vector2D operator- (const Vector2D& right_hand_side) const;
        const Vector2D& operator= (const Vector2D& right_hand_size);

        bool operator== (const Vector2D& right_hand_side) const;
        bool operator!= (const Vector2D& right_hand_side) const;
        bool operator!() const;
    };
} // namespace Recurring::Math
#endif
