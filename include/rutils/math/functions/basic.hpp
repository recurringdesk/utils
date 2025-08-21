#ifndef RE_BASIC_GUARD
#define RE_BASIC_GUARD

#include <rutils/core/api.hpp>

namespace Recurring::Math
{
    template <typename T>
    T RLIB square_root (T value);

    template <typename T>
    T RLIB pow (T base, T exponent);
} // namespace Recurring::Math

#endif // RE_BASIC_GUARD