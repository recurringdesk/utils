#pragma once

namespace Recurring::Math
{
    struct Vector4D
    {
        float x, y, z, w;
        float length () const;
        Vector4D (float x = 0.0f, float y = 0.0f, float z = 0.0f,
                  float w = 0.0f);
        Vector4D operator+ (const Vector4D& right_hand_side) const;
        Vector4D operator- (const Vector4D& right_hand_side) const;
    };
} // namespace Recurring::Math