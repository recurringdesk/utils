#include <recurring/math/constants.hpp>
#include <recurring/math/functions/convert.hpp>
#include <recurring/math/functions/square_root.hpp>
#include <recurring/math/functions/trigonometric_functions.hpp>
#include <xmmintrin.h>

#include <cmath>

// cmath just for sine, cosine and tanget. Using this temporarily.
// sin, cos, tan, sqrt...

namespace Recurring::Math
{
    template <>
    RLIB float
    radians_to_degrees (float angle)
    {
        const float angle_in_degrees = angle * (180.0f / PI<float>);
        return angle_in_degrees;
    }

    template <>
    RLIB double
    radians_to_degrees (double angle)
    {
        const double angle_in_degrees = angle * (180.0 / PI<float>);
        return angle_in_degrees;
    }

    template <>
    RLIB float
    degrees_to_radians (float angle)
    {
        float angle_in_radians = angle * (PI<float> / 180.0f);
        return angle_in_radians;
    }

    template <>
    RLIB double
    degrees_to_radians (double angle)
    {
        double angle_in_radians = angle * (PI<double> / 180.0);
        return angle_in_radians;
    }

    // Making all trigonometric functions a wrapper from std. I didn't get yet.

    template <>
    RLIB float
    sine (float angle)
    {
        return std::sinf (angle);
    }

    template <>
    RLIB double
    sine (double angle)
    {
        return std::sin (angle);
    }

    template <>
    RLIB float
    cosine (float angule)
    {
        return std::cosf (angule);
    }

    template <>
    RLIB double
    cosine (double angle)
    {
        return std::cos (angle);
    }

    template <>
    RLIB float
    tangent (float angle)
    {
        return std::tanf (angle);
    }

    template <>
    RLIB double
    tangent (double angle)
    {
        return std::tan (angle);
    }

    template <>
    RLIB float
    square_root (float value)
    {
        return std::sqrtf (value);
    }

    template <>
    RLIB double
    square_root (double value)
    {
        return std::sqrt (value);
    }
} // namespace Recurring::Math