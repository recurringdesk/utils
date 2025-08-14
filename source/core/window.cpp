#include "recurring/console/logger.hpp"
#include <GLFW/glfw3.h>
#include <recurring/core/window.hpp>
using Log = Recurring::Console::Logger;

namespace Recurring::Engine::Core
{
    struct Window::Handle
    {
        Handle ()
        {
            if (!glfwInit ())
            {
                throw 1;
            }
            Log::print (Log::DEBUGGING, "Initted window handler");
        }

        void
        create_window (int width, int height, const char* title)
        {
            window
                = glfwCreateWindow (800, 600, "Recurring", nullptr, nullptr);
        }

        void
        poll_events () const
        {
            glfwPollEvents ();
        }

        bool
        should_close () const
        {
            return glfwWindowShouldClose (window);
        }

      private:
        GLFWwindow* window;
    };

    Window::Window ()
    {
        handle = new Handle;
        handle->create_window (800, 600, "Title");
    }

    void
    Window::loop ()
    {
        while (!handle->should_close ())
        {
            handle->poll_events();
        }
    }

} // namespace Recurring::Engine::Core
