#ifndef RE_CORE_WINDOW
#define RE_CORE_WINDOW

#include "node.hpp"
#include <recurring/core/node.hpp>
#include <recurring/utils/string.hpp>

typedef struct GLFWwindow Handle;

namespace Recurring::System
{
    // Idk if Window must be part of system. Yeah, it's a wrapper for GLFW,
    // because it's gonna be painful to implement Wayland, X11 or even WinAPI from scratch. - 2025-17-08

    class RLIB Window
    {
        String title = nullptr;
        Handle* id = nullptr;

    public:
        Window ();
        ~Window ();

        int create (int width, int height, const char* title = nullptr);
        static int make_context_current (Handle* id);
        void destroy ();
        bool should_close () const;
        void poll_events () const;
        void wait_events () const;
        void swap_buffers () const;
        void set_title (const String& title);
        const String& get_title () const;
        Handle* get_id () const;
    };

    class RLIB MainLoop
    {
        Window& window;
        Core::Node& node;

    public:
        MainLoop (Window& window, Core::Node& scene);

        virtual int
        run ();
    };
} // namespace Recurring::System

#endif // RE_CORE_WINDOW