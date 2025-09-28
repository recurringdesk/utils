#ifndef CARD_GUARD
#define CARD_GUARD

namespace Sixty::Console
{
    struct [[deprecated]] Card
    {
        const char* color;
        const char* title;
    };
} // namespace Sixty::Console

#endif
