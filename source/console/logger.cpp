#include <recurring/console/logger.hpp>

namespace Recurring::Console
{
    RLIB void
    Logger::set_debug (bool mode)
    {
        debug_mode = mode;
    }
} // namespace Recurring::Console
