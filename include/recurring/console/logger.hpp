#ifndef RE_LOGGER_GUARD
#define RE_LOGGER_GUARD
#include <print>
#include <recurring/console/card.hpp>
#include <recurring/utils/api.hpp>
#include <recurring/utils/string.hpp>

namespace Recurring::Console
{
    class RLIB Logger
    {

    public:
        static inline bool debug_mode = false;

        // The "kind" of any println. It's gonna be putted on the left side.
        static constexpr Card WARNING = { Color::YELLOW, Title::WARNING };
        static constexpr Card INFO = { Color::GREEN, Title::INFO };
        static constexpr Card ERROR = { Color::RED, Title::ERROR };
        static constexpr Card DEBUG = { Color::GRAY, Title::DEBUGGING };
        static constexpr Card GENERIC = { Color::WHITE, Title::GENERIC };

        template <typename... Args>
        static void
        print (const char* description, Args&&... args)
        {
            std::print ("{}\n", std::vformat (description, std::make_format_args (args...)));
        }

        template <typename... Args>
        static void
        print (const Card& card, const char* description, Args&&... args)
        {
            if (!debug_mode && String::compare (card.title, DEBUG.title))
            {
                return;
            }
            std::print ("[{2}{0}{3}] {1}\n", card.title, std::vformat (description, std::make_format_args (args...)), card.color, Color::RESET);
        }
    };
} // namespace Recurring::Console
#endif // RE_LOGGER_GUARD