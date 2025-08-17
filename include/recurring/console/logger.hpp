#ifndef RE_LOGGER_GUARD
#define RE_LOGGER_GUARD
#include <iostream>
#include <recurring/console/card.hpp>
#include <recurring/utils/api.hpp>
#include <recurring/utils/string.hpp>

#ifndef DEBUG
#define LOG_DEBUG(description) std::cout << description << '\n';
#else
#define LOG_DEBUG(description)
#endif

namespace Recurring::Console
{
    struct RLIB Logger
    {

        // The "kind" of any println. It's gonna be putted on the left side.
        static constexpr Card WARNING = { Color::YELLOW, Title::WARNING };
        static constexpr Card INFO = { Color::GREEN, Title::INFO };
        static constexpr Card ERROR = { Color::RED, Title::ERROR };
        static constexpr Card GENERIC = { Color::WHITE, Title::GENERIC };

        // @todo Some kinda Variant type, like godot. To see how it works.

        template <typename... Args>
        static void
        print (Args&&... args)
        {
            ((std::cout << ... << args) << '\n');
        }

        template <typename... Args>
        static void
        print (const Card& card, Args&&... args)
        {
            (((std::cout << '[' << card.color << card.title << Color::RESET << ']' << ' ') << ... << args) << '\n');
        }
    };
} // namespace Recurring::Console
#endif // RE_LOGGER_GUARD