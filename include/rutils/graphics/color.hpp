#ifndef RE_COLOR_GUARD
#define RE_COLOR_GUARD

namespace Recurring
{
    /* 64::00 | 2025-08-26 20:14:43
    Move implementation to its own file
    and add upcoming blending functions.
    */

    struct Color
    {
        float red = 0.0f;
        float green = 0.0f;
        float blue = 0.0f;
        float alpha = 1.0f;

        Color (float red, float green, float blue, float alpha = 1.0)
            : red (red), green (green), blue (blue), alpha (alpha)
        {
        }

        Color ()
            : red (0.0f), green (0.0f), blue (0.0f), alpha (1.0f)
        {
        }
    };
} // namespace Recurring
#endif // RE_COLOR_GUARD
