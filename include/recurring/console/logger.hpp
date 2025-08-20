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

/* 2025-08-19
I'm afraid turning this library extremely overheaded.

It's OK if it's overheaded, but, turning it
horrible in too many ways that I can't even use it in the future.
*/

namespace Recurring::Console
{
    /* 64::00 | 2025-08-19
    ChatGPT gave me the next line. In 2 years of C++ I've never seen this before.
    I don't know what is a concept, actually. Is it to say "Hey! You can't do this
    in this line!"? If yes, I'm gonna try use it anywhere.

    It's gonna push to "os" the received value, and it's gonna verify if it's
    compatible with ostream.

    I don't know what's that "->" yet...
    */

    template <typename Arg>
    concept Streamable = requires (std::ostream& os, Arg&& arg) { { os << std::forward<Arg> (arg) } -> std::same_as<std::ostream&>; };

    // @todo Make Logger a true logger. Adding buffer member, and saving the content into a file!

    class RLIB Logger
    {
        Utils::String buffer; // For each print from an instance of Logger, it prints here.

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
            requires (Streamable<Args> && ...)
        {
            ((std::cout << ... << args) << '\n');
        }

        template <typename... Args>
        static void
        print (const Card& card, Args&&... args)
            requires (Streamable<Args> && ...)
        {
            (((std::cout << '[' << card.color << card.title << Text::Color::RESET << ']' << ' ') << ... << args) << '\n');
        }
    };
} // namespace Recurring::Console
#endif // RE_LOGGER_GUARD