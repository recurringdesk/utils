#pragma once

#include <glad/glad.h>

namespace Recurring::Core::Graphics // For now.
{
    struct BufferObject
    {
        GLuint id = 0;
        GLsizei size = 0;
        GLenum target = GL_ARRAY_BUFFER;
        GLenum usage = GL_STATIC_DRAW;

        BufferObject (GLenum target, GLenum usage, GLsizei size);
        ~BufferObject ();

        void bind () const;
        void unbind () const;
    };

    class BufferManager
    {
        BufferObject vertex_buffer;

    public:
        BufferManager (BufferObject& vertex_buffer);
    };
} // namespace Recurring::Core::Graphics