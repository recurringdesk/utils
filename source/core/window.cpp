#include <GLFW/glfw3.h>
#include <recurring/console/logger.hpp>
#include <recurring/core/window.hpp>

using Log = Recurring::Console::Logger;

namespace Recurring
{
    // @todo Move this one to its own header
    enum Error
    {
        GLFW_NOT_INITTED = 1,
        FAILED_TO_CREATE_HANDLE
    };
} // namespace Recurring

namespace Recurring::Engine::Core
{
    struct Window::Handle
    {
        void create (int width, int height, const char* title = nullptr);
        bool should_close () const;
        void poll_events ();

      private:
        GLFWwindow* handle;
    };

    Window::Window ()
    {
        handle = new Handle;
        handle->create (800, 600);
    }

    void
    Window::loop ()
    {
        if (!handle)
        {
            Log::print (Log::ERROR, "No window to loop");
            return;
        }

        while (!handle->should_close ())
        {
            handle->poll_events ();
        }
    }

    void
    Window::Handle::create (int width, int height, const char* title)
    {
        if (!glfwInit ())
        {
            Log::print ("GLFW not initted");
            throw Error::GLFW_NOT_INITTED;
        }
        if (!title)
            title = "Untitled";
        handle = glfwCreateWindow (width, height, title, nullptr, nullptr);
        if (!handle)
        {
            Log::print (Log::ERROR, "Failed to create handle");
            throw Error::FAILED_TO_CREATE_HANDLE;
        }
        Log::print (Log::DEBUG, "created glfw window");
    }

    bool
    Window::Handle::should_close () const
    {
        return glfwWindowShouldClose (handle);
    }

    void
    Window::Handle::poll_events ()
    {
        glfwPollEvents ();
    }
} // namespace Recurring::Engine::Core
