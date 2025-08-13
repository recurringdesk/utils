#pragma once

namespace Recurring::Engine
{

    class Window
    {
        struct Handle;
        Handle* handle;

      public:
        Window ();
        ~Window();
    };
} // namespace Recurring::Engine