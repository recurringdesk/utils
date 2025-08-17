#ifndef RE_CONSTANTS_GUARD
#define RE_CONSTANTS_GUARD

namespace Recurring::Math
{
    // Templating PI is the worst ideia I had, LOL
    // Like, calling PI<float> to be a float is kinda sick. - 2025-08-17

    template <typename T>
    constexpr T PI = T (3.141592653589793L);
} // namespace Recurring::Math
#endif // RE_CONSTANTS_GUARD