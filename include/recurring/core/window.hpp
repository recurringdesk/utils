#pragma once

#include "recurring/utils/string.hpp"
using Recurring::String;

namespace Recurring::Engine::Core
{
    class Window
    {
        String title;
        struct Handle;
        Handle* handle;

      public:
        Window ();
        virtual void loop();
    };
} // namespace Recurring::Engine::Core