#include <recurring/console/logger.hpp>
#include <recurring/utils/string.hpp>
#include <cstdarg>

namespace Recurring::Console
{
    void
    Logger::print (const String& description, ...)
    {
    }

    void
    Logger::set_debug (bool mode)
    {
        debug_mode = mode;
    }
} // namespace Recurring::Console
