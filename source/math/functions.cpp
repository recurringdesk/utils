#include <rutils/math/constants.hpp>
#include <rutils/math/functions/convert.hpp>
#include <rutils/math/functions/basic.hpp>
#include <rutils/math/functions/trigonometric_functions.hpp>
#include <xmmintrin.h>

#include <cmath>

// cmath just for sine, cosine and tanget. Using this temporarily.
// sin, cos, tan, sqrt...

// Math is literally a wrapper for cmath? Go to hell which one had this big idea... (to me) - 2025-08-17

namespace Recurring::Math
{
    template <>
    RLIB float
    pow (float base, float exponent)
    {
        /*
        if (exponent == 0.0f)
            return 1.0f;
        exponent must multiply base by its value.
        if exponent = 4, base * base * base * base - 2025-08-20
        */

        return std::powf (base, exponent);
    }

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

    // I'm just too lazy to get it... Motivation is tired. - 2025-08-17

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