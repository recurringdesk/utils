#include <glad/glad.h>
#include <recurring/utils/error.hpp>

#include <GLFW/glfw3.h>
#include <recurring/console/logger.hpp>
#include <recurring/core/window.hpp>

using Log = Recurring::Console::Logger;

namespace Recurring::Core::Graphics
{
    RLIB
    Window::Window ()
    {
        if (!glfwInit ())
            throw Error::GLFW_NOT_INITTED;
    }

    RLIB Window::~Window ()
    {
        destroy ();
        glfwTerminate ();
    }

    RLIB void
    Window::process ()
    {
    }

    RLIB void
    Window::create (int width, int height, const char* title)
    {
        if (!title)
            title = "Untitled";
        id = glfwCreateWindow (width, height, title, nullptr, nullptr);
        if (!id)
            throw Error::FAILED_TO_ALLOCATE_MEMORY;
    }

    RLIB void
    Window::destroy ()
    {
        if (id)
            glfwDestroyWindow (id);
    }

    RLIB bool
    Window::should_close () const
    {
        return glfwWindowShouldClose (id);
    }

    RLIB void
    Window::poll_events () const
    {
        glfwPollEvents ();
    }

    RLIB void
    Window::wait_events () const
    {
        glfwWaitEvents ();
    }

    RLIB void
    Window::swap_buffers () const
    {
        glfwSwapBuffers (id);
    }

    RLIB void
    Window::set_title (const String& title)
    {
        this->title = title;
    }

    RLIB String
    Window::get_title () const
    {
        return title;
    }
} // namespace Recurring::Core::Graphics
