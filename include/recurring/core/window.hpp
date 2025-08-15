#pragma once

#include <recurring/core/renderer.hpp>
#include <recurring/utils/string.hpp>

using Recurring::String;

namespace Recurring::Engine::Core
{
    class Window
    {
    private:
        String title;

    protected:
        virtual void main_loop () = 0;

    public:
        Window () = default;
        virtual void process () {};
        virtual ~Window () = default;
        virtual void create (int width, int height, const char* title = nullptr) = 0;
        virtual bool should_close () const = 0;
        virtual void poll_events () const = 0;
        virtual void wait_event () const = 0;
        virtual void swap_buffers () const = 0;
        void set_title (const String& title);
        String get_title () const;
    };
} // namespace Recurring::Engine::Core