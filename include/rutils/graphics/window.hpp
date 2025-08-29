#ifndef WINDOW_GUARD
#define WINDOW_GUARD

#include <rutils/core/string.hpp>
#include <rutils/graphics/color.hpp>
#include <rutils/graphics/node.hpp>

/* 64::00 | 2025-08-27 13:59:43
---
I plan not using glfw in the future.
glfw is awesome and I can even port it to macos,
but I feel that sometime it's gonna limit
myself. Not now, not even in 5 years... Maybe never.
*/

typedef struct GLFWwindow _RE_INTERNAL_WindowHandle;

namespace Recurring::System::OpenGL
{
    using Core::String;

    // Idk if Window must be part of system. Yeah, it's a wrapper for GLFW,
    // because it's gonna be painful to implement Wayland, X11 or even WinAPI from scratch. - 2025-17-08

    class Context
    {
        String title = nullptr;
        _RE_INTERNAL_WindowHandle* id = nullptr;
        Core::Node* current_node = nullptr;

    protected:
        int make_context_current () const;
        virtual void
        internal_loop (Core::Node* node);

    public:
        Context (Core::Node* node = nullptr);
        ~Context ();

        typedef void (*framebuffer_size) (_RE_INTERNAL_WindowHandle* id, int width, int height);
        int set_framebuffer_size_callback (framebuffer_size) const;

        /**
         * @brief Creates a window using GLFW!
         *
         * @param width It's the x size!
         * @param height It's the y size!
         * @param title The text in the window header!
         * @return int
         */
        int
        create (int width, int height, const char* title = nullptr);

        /**
         * @brief Will serve as "v-sync". Idk, it's the same ideia.
         *
         * @param value
         */
        void swap_interval (int value) const;

        /**
         * @brief Call it to destroy the existence window.
         *
         * @return int
         */
        int destroy ();
        bool should_close () const;
        void poll_events () const;
        void wait_events () const;
        void swap_buffers () const;
        int set_title (const String& title);
        const String& get_title () const;
        _RE_INTERNAL_WindowHandle* get_id () const;
        void set_id (_RE_INTERNAL_WindowHandle* id);
        virtual int
        run ();
        void clear_color (const Color& color);
    };
} // namespace Recurring::System::OpenGL

#endif
