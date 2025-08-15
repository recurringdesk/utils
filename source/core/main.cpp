#include "recurring/core/window.hpp"
#include <recurring/console/logger.hpp>
#include <recurring/utils/error.hpp>
using Log = Recurring::Console::Logger;
using Recurring::Engine::Core::Window;
using Error = Recurring::Error;

class OpenGLWindow : public Window
{
    struct Handle;
    Handle* handle;

protected:
    virtual void main_loop () override;

public:
    OpenGLWindow ();
    ~OpenGLWindow ();
    void swap_buffers () const override;
    void process () override;
    void create (int width, int height, const char* title = nullptr) override;
    bool should_close () const override;
    void poll_events () const override;
    void wait_event () const override;
};

int
main ()
{
    Log::print (Log::INFO, "Hello, world!");
    OpenGLWindow main_window;
    main_window.create (800, 600);
    return 0;
}

#include <glad/glad.h>

#include <GLFW/glfw3.h>

struct OpenGLWindow::Handle
{
    GLFWwindow* id;
};

void
OpenGLWindow::swap_buffers () const
{
    glfwSwapBuffers (handle->id);
}

void
OpenGLWindow::process ()
{
    glClear (GL_COLOR_BUFFER_BIT);
    glClearColor (0.0f, 0.0f, 0.0f, 1.0f);
    swap_buffers ();
}

OpenGLWindow::OpenGLWindow ()
    : handle (new Handle)
{
    if (!glfwInit ())
    {
        throw Error::GLFW_NOT_INITTED;
    }
}

OpenGLWindow::~OpenGLWindow ()
{
    glfwTerminate ();
}

void
OpenGLWindow::create (int width, int height, const char* title)
{
    if (!handle)
    {
        throw Error::FAILED_TO_ALLOCATE_MEMORY;
    }

    if (!title)
        title = "Untitled";

    handle->id = glfwCreateWindow (width, height, title, nullptr, nullptr);

    if (!handle->id)
    {
        throw Error::FAILED_TO_ALLOCATE_MEMORY;
    }

    glfwMakeContextCurrent (handle->id);

    gladLoadGLLoader ((GLADloadproc)glfwGetProcAddress);

    main_loop ();
}

void
OpenGLWindow::main_loop ()
{
    while (!should_close ())
    {
        process();
        poll_events ();
    }
}

void
OpenGLWindow::poll_events () const
{
    glfwPollEvents ();
}

void
OpenGLWindow::wait_event () const
{
    glfwWaitEvents ();
}

bool
OpenGLWindow::should_close () const
{
    return glfwWindowShouldClose (handle->id);
}