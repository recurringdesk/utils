#ifndef RE_CORE_WINDOW
#define RE_CORE_WINDOW

#include <recurring/utils/string.hpp>

typedef struct GLFWwindow Handle;

namespace Recurring::Core::Graphics
{
    class RLIB Window
    {
    private:
        String title;
        Handle* id;

    public:
        Window ();
        ~Window ();

        virtual void process ();
        virtual void create (int width, int height, const char* title = nullptr);
        virtual void destroy ();
        virtual bool should_close () const;
        virtual void poll_events () const;
        virtual void wait_events () const;
        virtual void swap_buffers () const;
        void set_title (const String& title);
        String get_title () const;
    };
} // namespace Recurring::Core::Graphics

#endif // RE_CORE_WINDOW