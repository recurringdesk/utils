#pragma once

namespace Recurring::Engine::Graphics
{
    class Renderer
    {
      public:
        virtual void draw () = 0;
        virtual ~Renderer () = default;
    };

    class OpenGL : public Renderer
    {
      public:
        OpenGL ();
    };
} // namespace Recurring::Engine::Graphics