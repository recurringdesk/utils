#pragma once

#include <recurring/core/renderer.hpp>
#include <recurring/utils/string.hpp>

using Recurring::String;
using Recurring::Engine::Graphics::Renderer;

namespace Recurring::Engine::Core
{
    class Window
    {
        String title;
        Renderer* renderer;
        struct Handle;
        Handle* handle;

      public:
        Window ();
        void set_renderer (Renderer* renderer);
        virtual void loop ();
    };
} // namespace Recurring::Engine::Core