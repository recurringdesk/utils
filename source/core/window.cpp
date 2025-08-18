#include <GL/glew.h>
#include <recurring/utils/error.hpp>

#include <GLFW/glfw3.h> // I love wrapping libraries to my own library because. - 2025-08-18
#include <recurring/console/logger.hpp>
#include <recurring/core/window.hpp>

using Log = Recurring::Console::Logger;

namespace Recurring::System
{
    RLIB void
    Window::internal_loop (Core::Node* node)
    {
        node->process ();
        swap_buffers ();
        wait_events ();
    }

    RLIB int
    Window::run (Core::Node* node)
    {
        if (!get_id ())
        {
            Log::print (Log::ERROR, "No window to loop!");
            return Error::NO_WINDOW_TO_LOOP;
        }

        LOG_DEBUG ("There is a window")

        if (!glfwGetCurrentContext ())
        {
            Log::print (Log::ERROR, "No window to loop.");
            return Error::CONTEXT_WAS_NOT_MAKE;
        }

        LOG_DEBUG ("There is a context");

        if (!node)
            node = new Core::Node;

        node->ready ();

        LOG_DEBUG ("Node is ready")

        while (!should_close ())
        {
            internal_loop (node);
        }
        return Error::SUCCESS;
    }

    RLIB Handle*
    Window::get_id () const
    {
        return id;
    }

    RLIB void
    Window::set_id (Handle* id)
    {
        this->id = id;
    }

    RLIB
    Window::Window ()
    {
        // Do you think creating an OpenGL app is the most funny thing?
        // No, it's not. It's painful. But I love being masochist.
        // Instead of hanging out with people,
        // helping my social skills... I'm here.
        // Programming things I'll never use in the real world.
        // Bjarne certainly wouldn't pride of me. - 2025-08-18

        Log::print (Log::WARNING, "Using 'class Window' is so funny!");
    }

    RLIB Window::~Window ()
    {
        // Do I really need this warning? YES.

        Log::print (Log::WARNING, "Deleting window");
        if (id)
            destroy ();
        glfwTerminate ();
    }

    RLIB int
    Window::create (int width, int height, const char* title)
    {
        // Added the next warning because it looks cool. Idk, it's useless.
        // At the first moment I thought "hum, cool. I'm gonna use it because
        // this module is experimental", but the whole library is something experimental.
        // Definitely, this was the first moment I thought
        // as the intelligent human being alive. - 2025-08-18

        if (get_id ())
            return Error::WINDOW_ALREADY_EXISTS;

        Log::print (Log::WARNING, "Creating window!");
        if (!title)
            this->title = "Untitled";
        else
            this->title = title;

        if (!glfwInit ())
            return Error::GLFW_NOT_INITED;

        set_id (glfwCreateWindow (width, height, this->title.raw (), nullptr, nullptr));
        if (!get_id ())
            return Error::MEMORY_NOT_ALLOCATED;

        if (const int error = make_context_current (); error != Error::SUCCESS)
            return error;

        return Error::SUCCESS;
    }

    RLIB void
    Window::swap_interval (int value) const
    {
        glfwSwapInterval (value);
    }

    RLIB int
    Window::make_context_current () const
    {
        glfwMakeContextCurrent (this->id);

        if (!glfwGetCurrentContext ())
            return Error::CONTEXT_WAS_NOT_MAKE;

        if (glewInit () != GLEW_OK)
            return Error::GLEW_NOT_INITED;

        return Error::SUCCESS;
    }

    RLIB int
    Window::destroy ()
    {
        if (!id)
            return Error::NO_WINDOW_TO_DESTROY;
        glfwDestroyWindow (id);
        return Error::SUCCESS;
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

    RLIB int
    Window::set_title (const String& title)
    {
        if (title.is_empty ())
            return Error::STRING_IS_EMPTY;
        this->title = title;
        return Error::SUCCESS;
    }

    RLIB const String&
    Window::get_title () const
    {
        return title;
    }
} // namespace Recurring::System
