#include <console/logger.hpp>
#include <window.hpp>
using Log = Recurring::Console::Logger;
using Recurring::Engine::Window;
int main()
{
    Log::print(Log::INFO, "Hello, world!");
    Window window;
    return 0;
}