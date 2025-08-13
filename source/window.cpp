#include "console/logger.hpp"
#include <GLFW/glfw3.h>
#include <window.hpp>

using Log = Recurring::Console::Logger;

namespace Recurring::Engine
{
    struct Window::Handle
    {
        Handle ()
        {
            if (!glfwInit ())
            {
                Log::print (Log::ERROR, "Failed initting glfw");
                return;
            }
            Log::print (Log::INFO, "glfw initted");
        }
    };

    Window::Window () {}

    Window::~Window () {}
} // namespace Recurring::Engine