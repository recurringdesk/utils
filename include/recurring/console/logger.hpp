#ifndef RE_LOGGER_GUARD
#define RE_LOGGER_GUARD
#include <iostream>
#include <recurring/console/card.hpp>
#include <recurring/console/text.hpp>
#include <recurring/utils/api.hpp>
#include <recurring/utils/string.hpp>

#ifndef DEBUG
#define LOG_DEBUG(description) std::cout << description << '\n';
#else
#define LOG_DEBUG(description)
#endif

namespace Recurring::Console
{
    // @todo Make Logger a true logger. Adding buffer member, and saving the content into a file!

    class RLIB Logger
    {
        String buffer; // For each print from an instance of Logger, it prints here.

    public:
        // The "kind" of any println. It's gonna be putted on the left side.
        static constexpr Card WARNING = { Text::Color::YELLOW, Text::Title::WARNING };
        static constexpr Card INFO = { Text::Color::GREEN, Text::Title::INFO };
        static constexpr Card ERROR = { Text::Color::RED, Text::Title::ERROR };
        static constexpr Card GENERIC = { Text::Color::WHITE, Text::Title::GENERIC };

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
            (((std::cout << '[' << card.color << card.title << Text::Color::RESET << ']' << ' ') << ... << args) << '\n');
        }
    };
} // namespace Recurring::Console
#endif // RE_LOGGER_GUARD