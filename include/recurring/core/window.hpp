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

    protected:
        int make_context_current () const;
        virtual void
        internal_loop (Core::Node* node);

    public:
        Window ();
        ~Window ();

        /**
         * @brief Creates a window using GLFW!
         *
         * @param width It's the x size!
         * @param height It's the y size!
         * @param title The text in the window header!
         * @return int
         */
        int create (int width, int height, const char* title = nullptr);

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
        Handle* get_id () const;
        void set_id (Handle* id);
        virtual int
        run (Core::Node* node = nullptr);
    };
} // namespace Recurring::System

#endif // RE_CORE_WINDOW