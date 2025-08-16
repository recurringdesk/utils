#ifndef RE_LOGGER_GUARD
#define RE_LOGGER_GUARD
#include <print>
#include <recurring/console/card.hpp>
#include <recurring/utils/api.hpp>

namespace Recurring::Console
{
    class RLIB Logger
    {
        static inline bool debug_mode = false;

    public:
        static constexpr Card WARNING
            = { Card::Color::YELLOW, Card::Title::WARNING };
        static constexpr Card INFO = { Card::Color::GREEN, Card::Title::INFO };
        static constexpr Card ERROR = { Card::Color::RED, Card::Title::ERROR };
        static constexpr Card DEBUG
            = { Card::Color::GRAY, Card::Title::DEBUGGING };
        static constexpr Card GENERIC
            = { Card::Color::WHITE, Card::Title::GENERIC };

        static void set_debug (bool mode);

        template <typename... Args>
        static void
        print (const char* description, Args&&... args)
        {
            std::print (
                "{}\n",
                std::vformat (description, std::make_format_args (args...)));
        }

        template <typename... Args>
        static void
        print (const Card& card, const char* description, Args&&... args)
        {
            std::print (
                "[{2}{0}{3}] {1}\n", card.title,
                std::vformat (description, std::make_format_args (args...)),
                card.color, Card::Color::RESET);
        }
    };
} // namespace Recurring::Console
#endif // RE_LOGGER_GUARD