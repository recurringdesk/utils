#include "recurring/core/window.hpp"
#include <recurring/console/logger.hpp>
using Log = Recurring::Console::Logger;
using Recurring::Engine::Core::Window;

int
main ()
{
    Log::print(Log::INFO, "Hello, world!");
    Window window;
    window.loop();
    return 0;
}