#pragma once

namespace Recurring::Math
{
    struct Vector3D
    {
        float x, y, z;
        float length () const;
        Vector3D (float x = 0.0f, float y = 0.0f, float z = 0.0f);
        Vector3D operator+ (const Vector3D& right_hand_side) const;
        Vector3D operator- (const Vector3D& right_hand_side) const;
    };
} // namespace Recurring::Math