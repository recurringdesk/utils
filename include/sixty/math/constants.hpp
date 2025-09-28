#ifndef CONSTANTS_GUARD
#define CONSTANTS_GUARD

namespace Sixty::Math
{
    // Templating PI is the worst ideia I had, LOL
    // Like, calling PI<float> to be a float is kinda sick. - 2025-08-17

    template <typename T>
    constexpr T PI = T (3.141592653589793L);
} // namespace Sixty::Math
#endif
