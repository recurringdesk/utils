#include <glad/glad.h>
#include <recurring/utils/error.hpp>

#include <GLFW/glfw3.h>
#include <recurring/console/logger.hpp>
#include <recurring/core/window.hpp>

using Log = Recurring::Console::Logger;

namespace Recurring::System
{
    RLIB
    MainLoop::MainLoop (Window& window, Core::Node& scene)
        : window (window), scene (&scene)
    {
        if (!this->window.get_id ())
        {
            Log::print (Log::WARNING, "Did you forget to create the window?");
            return;
        }
    }

    RLIB int
    MainLoop::run ()
    {
        if (!this->window.get_id ())
        {
            Log::print (Log::ERROR, "No window to loop.");
            return Error::NO_WINDOW_TO_LOOP;
        }
        while (!window.should_close ())
        {
            scene->process ();
            window.swap_buffers ();
            window.poll_events ();
        }
        return Error::SUCCESS;
    }

    RLIB
    Window::Window ()
    {
        if (!glfwInit ())
            throw Error::GLFW_NOT_INITED;
    }

    Handle*
    Window::get_id () const
    {
        return id;
    }

    RLIB Window::~Window ()
    {
        destroy ();
        glfwTerminate ();
    }

    RLIB void
    Window::create (int width, int height, const char* title)
    {
        if (!title)
            title = "Untitled";
        id = glfwCreateWindow (width, height, title, nullptr, nullptr);
        if (!id)
            throw Error::MEMORY_NOT_ALLOCATED;
        glfwMakeContextCurrent (id);
        if (!gladLoadGLLoader ((GLADloadproc)glfwGetProcAddress))
        {
            throw Error::OPENGL_NOT_LOADED;
        }
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

    RLIB const String&
    Window::get_title () const
    {
        return title;
    }
} // namespace Recurring::System
