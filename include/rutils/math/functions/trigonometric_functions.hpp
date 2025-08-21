#ifndef RE_TRIGO_FUNC_GUARD
#define RE_TRIGO_FUNC_GUARD

#include <rutils/core/api.hpp>

namespace Recurring::Math
{
    /**
     * @brief The "X" value of a circle.
     *
     * @tparam T
     * @param angle In radians
     * @return T
     */
    template <typename T>
    RLIB T sine (T angle);

    /**
     * @brief The "Y" value of a circle
     *
     * @tparam T
     * @param angle
     * @return T
     */
    template <typename T>
    RLIB T cosine (T angle);

    /**
     * @brief Computes the tangent of the given angle (sin(angle) /
     * cos(angle)).
     *
     * @tparam T float, double, etc.
     * @param angle Angle in radians.
     * @return T The tangent of the angle.
     */
    template <typename T>
    RLIB T tangent (T angle);
} // namespace Recurring::Math

#endif // RE_TRIGO_FUNC_GUARD