#ifndef RE_LOGGER_GUARD
#define RE_LOGGER_GUARD
#include <iostream>
#include <rutils/console/card.hpp>
#include <rutils/console/text.hpp>
#include <rutils/core/api.hpp>
#include <rutils/core/string.hpp>

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
    /*
    ChatGPT gave me the next line. In 2 years of C++ I've never seen this before.
    I don't know what is a concept, actually. Is it to say "Hey! You can't do this
    in this line!"? If yes, I'm gonna try use it anywhere.

    It's gonna push to "os" the received value, and it's gonna verify if it's
    compatible with ostream.

    I don't know what's that "->" yet... - 64::00 | 2025-08-19

    Decided to remove it. It maybe useful, but not for now. Later I decide what happens to it.

    template <typename Arg>
    concept Streamable = requires (std::ostream& os, Arg&& arg) { { os << std::forward<Arg> (arg) } -> std::same_as<std::ostream&>; };

    template <typename... Args>
    static void
    print (Args&&... args)
        requires (Streamable<Args> && ...)
    {
        ((std::cout << ... << args) << '\n');
    }

    - 64::00 | 2025-08-21
    */

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
        {

            /*
            Some I can't do this...

            std::cout << (... << std::forward<Args> (args)) << '\n';

            It gives me "error: invalid operands to binary expression ('const char[3]' and 'int')"
            I know << is a bitwise... so using () makes << detect as a bitwise operator? Because
            they are the first to be solved?

            Idk how << is working on here, actually. I know << is a bitwise because
            there are a ton of videos on youtube using it.

            - 64::00 2025-08-21
            */

            (std::cout << ... << std::forward<Args> (args)) << '\n';
        }

        template <typename... Args>
        static void
        print (const Card& card, Args&&... args)
        {
            std::cout << '[' << card.color << card.title << Text::Color::RESET << ']' << ' ' << (... << std::forward<Args> (args)) << '\n';
        }
    };
} // namespace Recurring::Console
#endif // RE_LOGGER_GUARD