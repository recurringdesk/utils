#include <recurring/console/logger.hpp>
#include <recurring/core/window.hpp>

using Recurring::Core::Graphics::Window;
using Log = Recurring::Console::Logger;
int main()
{
    Log::print("OK");
    Window window;
    window.create(800, 600);
    while (!window.should_close())
    {
        window.wait_events();
    }
    return 0;
}