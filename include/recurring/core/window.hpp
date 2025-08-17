#ifndef RE_CORE_WINDOW
#define RE_CORE_WINDOW

#include "node.hpp"
#include <recurring/core/node.hpp>
#include <recurring/utils/string.hpp>

typedef struct GLFWwindow Handle;

namespace Recurring::System
{
    class RLIB Window
    {
        String title;
        Handle* id;

    public:
        Window ();
        ~Window ();

        virtual void create (int width, int height, const char* title = nullptr);
        virtual void destroy ();
        virtual bool should_close () const;
        virtual void poll_events () const;
        virtual void wait_events () const;
        virtual void swap_buffers () const;
        void set_title (const String& title);
        const String& get_title () const;
        Handle* get_id () const;
    };

    class RLIB MainLoop
    {
        Window window;
        Core::Node* scene;

    public:
        MainLoop (Window& window, Core::Node& scene);

        virtual int
        run ();
    };
} // namespace Recurring::System

#endif // RE_CORE_WINDOW