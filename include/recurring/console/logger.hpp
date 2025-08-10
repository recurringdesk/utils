#pragma once
#include <recurring/utils/string.hpp>

namespace Recurring::Console
{
    struct Card;

    class Logger
    {
        static inline bool debug_mode = false;

      public:
        static void set_debug (bool mode);

        static void print (const Card& card, const String& description, ...);
        static void print (const String& description, ...);
    };
} // namespace Recurring::Console