#include <recurring/utils/error.hpp>
#include <glad/glad.h>

#include <GLFW/glfw3.h>
#include <recurring/console/logger.hpp>
#include <recurring/core/window.hpp>

using Log = Recurring::Console::Logger;

namespace Recurring::Core::Graphics
{
    Window::Window ()
    {
        if (!glfwInit ())
            throw Error::GLFW_NOT_INITTED;
    }

    Window::~Window ()
    {
        glfwTerminate ();
    }

    void
    Window::process ()
    {
    }

    void
    Window::create (int width, int height, const char* title)
    {
        id = glfwCreateWindow (width, height, title, nullptr, nullptr);
        if (!id)
            throw Error::FAILED_TO_ALLOCATE_MEMORY;
    }

    void
    Window::destroy ()
    {
        if (id)
            glfwDestroyWindow (id);
    }

    bool
    Window::should_close () const
    {
        return glfwWindowShouldClose (id);
    }

    void
    Window::poll_events () const
    {
        glfwPollEvents ();
    }

    void
    Window::wait_events () const
    {
        wait_events ();
    }

    void
    Window::swap_buffers () const
    {
        glfwSwapBuffers (id);
    }

    void
    Window::set_title (const String& title)
    {
        this->title = title;
    }

    String
    Window::get_title () const
    {
        return title;
    }
} // namespace Recurring::Core::Graphics
