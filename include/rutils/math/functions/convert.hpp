#ifndef RE_CNVT_GUARD
#define RE_CNVT_GUARD

#include <rutils/core/api.hpp>

namespace Recurring::Math
{
    template <typename T>
    T RLIB degrees_to_radians (T angle);
    template <typename T>
    T RLIB radians_to_degrees (T angle);
} // namespace Recurring::Math

#endif // RE_CNVT_GUARD