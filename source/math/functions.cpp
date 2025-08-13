#include <math/constants.hpp>
#include <math/functions/convert.hpp>
#include <math/functions/square_root.hpp>
#include <math/functions/trigonometric_functions.hpp>
#include <xmmintrin.h>

#include <cmath>

// cmath just for sine, cosine and tanget. Using this temporarily.
// sin, cos, tan, sqrt...

namespace Recurring::Math
{
    template <>
    float
    radians_to_degrees (float angle)
    {
        const float angle_in_degrees = angle * (180.0f / PI<float>);
        return angle_in_degrees;
    }

    template <>
    double
    radians_to_degrees (double angle)
    {
        const double angle_in_degrees = angle * (180.0 / PI<float>);
        return angle_in_degrees;
    }

    template <>
    float
    degrees_to_radians (float angle)
    {
        float angle_in_radians = angle * (PI<float> / 180.0f);
        return angle_in_radians;
    }

    template <>
    double
    degrees_to_radians (double angle)
    {
        double angle_in_radians = angle * (PI<double> / 180.0);
        return angle_in_radians;
    }

    // Making all trigonometric functions a wrapper from std. I didn't get yet.

    template <>
    float
    sine (float angle)
    {
        return std::sinf (angle);
    }

    template <>
    double
    sine (double angle)
    {
        return std::sin (angle);
    }

    template <>
    float
    cosine (float angule)
    {
        return std::cosf (angule);
    }

    template <>
    double
    cosine (double angle)
    {
        return std::cos (angle);
    }

    template <>
    float
    tangent (float angle)
    {
        return std::tanf (angle);
    }

    template <>
    double
    tangent (double angle)
    {
        return std::tan (angle);
    }

    template <>
    float
    square_root (float value)
    {
        return std::sqrtf (value);
    }

    template <>
    double
    square_root (double value)
    {
        return std::sqrt (value);
    }
} // namespace Recurring::Math