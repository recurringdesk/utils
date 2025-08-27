#include <GL/glew.h>
#include <rutils/core/error.hpp>

#include <GLFW/glfw3.h> // I love wrapping libraries to my own library because. - 2025-08-18
#include <rutils/console/logger.hpp>
#include <rutils/graphics/window.hpp>

void
_RE_INTERNAL_set_framebuffer_callback (_RE_INTERNAL_WindowHandle*, int width, int height)
{
    glViewport (0, 0, width, height);
}

namespace Recurring::System::OpenGL
{
    using Recurring::Console::Logger;

    void
    Context::internal_loop (Core::Node* node)
    {
        node->process ();
        swap_buffers ();
        wait_events ();
    }

    int
    Context::run ()
    {
        if (!get_id ())
        {
            Logger::print (Logger::ERROR, "No window to loop!");
            return Error::NO_WINDOW_TO_LOOP;
        }

        if (!glfwGetCurrentContext ())
        {
            Logger::print (Logger::ERROR, "No current context!");
            return Error::CONTEXT_WAS_NOT_MAKE;
        }

        if (!current_node)
            current_node = new Core::Node;

        current_node->ready ();

        while (!should_close ())
        {
            internal_loop (current_node);
        }

        return Error::SUCCESS;
    }

    _RE_INTERNAL_WindowHandle*
    Context::get_id () const
    {
        return id;
    }

    void
    Context::set_id (_RE_INTERNAL_WindowHandle* id)
    {
        this->id = id;
    }

    Context::Context (Core::Node* node)
        : current_node (node)
    {
        // Do you think creating an OpenGL app is the most funny thing?
        // No, it's not. It's painful. But I love being masochist.
        // Instead of hanging out with people,
        // helping my social skills... I'm here.
        // Programming things I'll never use in the real world.
        // Bjarne certainly wouldn't pride of me. - 2025-08-18

        Logger::print (Logger::WARNING, "Using 'class Window' is so funny!");
    }

    Context::~Context ()
    {
        /* 64::00 | 2025-08-26 20:18:10
        For some random reason, deleting current_node
        even it's being allocated it gives me a segfault.
        I need fix this as soon.
        */

        if (current_node)
            delete current_node;
        if (id)
            destroy ();
        glfwTerminate ();
        Logger::print (Logger::WARNING, "Window was deleted");
    }

    int
    Context::create (int width, int height, const char* title)
    {
        // Added the next warning because it looks cool. Idk, it's useless.
        // At the first moment I thought "hum, cool. I'm gonna use it because
        // this module is experimental", but the whole library is something experimental.
        // Definitely, this was the first moment I thought
        // as the intelligent human being alive. - 2025-08-18

        if (get_id ())
            return Error::WINDOW_ALREADY_EXISTS;

        Logger::print (Logger::WARNING, "Creating window!");
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

        set_framebuffer_size_callback (_RE_INTERNAL_set_framebuffer_callback);
        return Error::SUCCESS;
    }

    int
    Context::set_framebuffer_size_callback (framebuffer_size callback) const
    {
        if (!get_id ())
            return Error::NO_WINDOW_TO_SET_FRAMEBUFFER_SIZE_CALLBACK;
        glfwSetFramebufferSizeCallback (get_id (), callback);
        return Error::SUCCESS;
    }

    void
    Context::swap_interval (int value) const
    {
        glfwSwapInterval (value);
    }

    int
    Context::make_context_current () const
    {
        glfwMakeContextCurrent (this->id);

        if (!glfwGetCurrentContext ())
            return Error::CONTEXT_WAS_NOT_MAKE;

        if (glewInit () != GLEW_OK)
            return Error::GLEW_NOT_INITED;

        return Error::SUCCESS;
    }

    void
    Context::clear_color (const Color& color)
    {
        glClear (GL_COLOR_BUFFER_BIT);
        glClearColor (color.red, color.green, color.blue, color.alpha);
    }

    int
    Context::destroy ()
    {
        if (!id)
            return Error::NO_WINDOW_TO_DESTROY;
        glfwDestroyWindow (id);
        return Error::SUCCESS;
    }

    bool
    Context::should_close () const
    {
        return glfwWindowShouldClose (id);
    }

    void
    Context::poll_events () const
    {
        glfwPollEvents ();
    }

    void
    Context::wait_events () const
    {
        glfwWaitEvents ();
    }

    void
    Context::swap_buffers () const
    {
        glfwSwapBuffers (id);
    }

    int
    Context::set_title (const Utils::String& title)
    {
        if (title.is_empty ())
            return Error::STRING_IS_EMPTY;
        this->title = title;
        return Error::SUCCESS;
    }

    const Utils::String&
    Context::get_title () const
    {
        return title;
    }
} // namespace Recurring::System::OpenGL
