#include <glad/glad.h>

#include <GLFW/glfw3.h>
#include <recurring/console/logger.hpp>
#include <recurring/core/window.hpp>

using Log = Recurring::Console::Logger;

namespace Recurring::Engine::Core
{
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
} // namespace Recurring::Engine::Core
