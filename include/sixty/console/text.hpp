#ifndef TEXT_GUARD
#define TEXT_GUARD

namespace Sixty::Console
{
    namespace Color
    {
        // constexpr is for the compilation time
        // inline is for multiple definitions

        // This is kinda horrible... but strangely works. - 2025-08-17

        [[deprecated]] inline constexpr const char* RESET = "\033[0m";
        [[deprecated]] inline constexpr const char* GREEN = "\033[32m";
        [[deprecated]] inline constexpr const char* RED = "\033[31;4m";
        [[deprecated]] inline constexpr const char* YELLOW = "\033[33m";
        [[deprecated]] inline constexpr const char* WHITE = "\033[37m";
        [[deprecated]] inline constexpr const char* GRAY = "\033[2;3m";
    } // namespace Color

    namespace Title
    {
        [[deprecated]] inline constexpr const char* GENERIC = "GENERIC";
        [[deprecated]] inline constexpr const char* INFO = "INFO";
        [[deprecated]] inline constexpr const char* ERROR = "ERROR";
        [[deprecated]] inline constexpr const char* DEBUGGING = "DEBUG";
        [[deprecated]] inline constexpr const char* WARNING = "WARNING";
    } // namespace Title
} // namespace Sixty::Console

#endif
