#ifndef CONVERT_GUARD
#define CONVERT_GUARD

#include <rutils/core/api.hpp>

namespace Recurring::Math
{
    template <typename T>
    T degrees_to_radians (T angle);
    template <typename T>
    T radians_to_degrees (T angle);
} // namespace Recurring::Math

#endif
