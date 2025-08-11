#pragma once

namespace Recurring::Math
{
    /**
     * @brief The "X" value of a circle.
     *
     * @tparam T
     * @param angle In radians
     * @return T
     */
    template <typename T> T sine (T angle);

    /**
     * @brief The "Y" value of a circle
     *
     * @tparam T
     * @param angle
     * @return T
     */
    template <typename T> T cosine (T angle);

    /**
     * @brief Computes the tangent of the given angle (sin(angle) /
     * cos(angle)).
     *
     * @tparam T float, double, etc.
     * @param angle Angle in radians.
     * @return T The tangent of the angle.
     */
    template <typename T> T tangent (T angle);
} // namespace Recurring::Math