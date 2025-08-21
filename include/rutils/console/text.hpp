#ifndef RE_TEXT_GUARD
#define RE_TEXT_GUARD

namespace Recurring::Console::Text
{
    namespace Color
    {
        // constexpr is for the compilation time
        // inline is for multiple definitions

        // This is kinda horrible... but strangely works. - 2025-08-17

        inline constexpr const char* RESET = "\033[0m";
        inline constexpr const char* GREEN = "\033[32m";
        inline constexpr const char* RED = "\033[31;4m";
        inline constexpr const char* YELLOW = "\033[33m";
        inline constexpr const char* WHITE = "\033[37m";
        inline constexpr const char* GRAY = "\033[2;3m";
    } // namespace Color

    namespace Title
    {
        inline constexpr const char* GENERIC = "GENERIC";
        inline constexpr const char* INFO = "INFO";
        inline constexpr const char* ERROR = "ERROR";
        inline constexpr const char* DEBUGGING = "DEBUG";
        inline constexpr const char* WARNING = "WARNING";
    } // namespace Title
} // namespace Recurring::Console::Text
#endif // RE_TEXT_GUARD