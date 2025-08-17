#include <glad/glad.h>
#include <recurring/utils/error.hpp>

#include <GLFW/glfw3.h>
#include <recurring/console/logger.hpp>
#include <recurring/core/window.hpp>
#include <thread>

using Log = Recurring::Console::Logger;

namespace Recurring::System
{
    RLIB
    MainLoop::MainLoop (Window& window, Core::Node& scene)
        : window (window), node (scene)
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

        Log::print (Log::INFO, "There is a window");

        if (!glfwGetCurrentContext ())
        {
            Log::print (Log::ERROR, "No window to loop.");
            return Error::CONTEXT_WAS_NOT_MAKE;
        }

        Log::print (Log::INFO, "There is context");

        node.ready ();

        Log::print (Log::INFO, "Node is ready");

        while (!window.should_close ())
        {
            node.process ();
            window.swap_buffers ();
            window.poll_events ();
        }
        return Error::SUCCESS;
    }

    Handle*
    Window::get_id () const
    {
        return id;
    }

    RLIB
    Window::Window ()
    {
        Log::print (Log::WARNING, "Using class Window is only for fun.");
    }

    RLIB Window::~Window ()
    {
        Log::print (Log::WARNING, "Deleting class Window in the thread ", std::this_thread::get_id ());
        if (id)
            destroy ();
        glfwTerminate ();
    }

    // @todo Make this per thread. I've tested

    RLIB int
    Window::create (int width, int height, const char* title)
    {
        Log::print (Log::WARNING, "Creating window in the thread -> ", std::this_thread::get_id ());
        if (!title)
            this->title = "Untitled";

        if (!glfwInit ())
            return Error::GLFW_NOT_INITED;

        id = glfwCreateWindow (width, height, this->title.raw (), nullptr, nullptr);
        if (!id)
            return Error::MEMORY_NOT_ALLOCATED;

        return make_context_current (id);
    }

    RLIB int
    Window::make_context_current (Handle* id)
    {
        glfwMakeContextCurrent (id);

        if (!glfwGetCurrentContext ())
            return Error::CONTEXT_WAS_NOT_MAKE;

        if (!gladLoadGLLoader ((GLADloadproc)glfwGetProcAddress))
            return Error::OPENGL_NOT_LOADED;

        return Error::SUCCESS;
    }

    RLIB void
    Window::destroy ()
    {
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
