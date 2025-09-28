#ifndef BUFFER_MANAGER_GUARD
#define BUFFER_MANAGER_GUARD

#include <GL/glew.h>

namespace Sixty::Graphics
{
    struct BufferObject
    {
        GLuint id;
        GLsizeiptr size;
        GLenum target;
        GLenum usage;

        BufferObject (GLenum target, GLenum usage, GLsizeiptr size);
        ~BufferObject ();

        void bind () const;
        void unbind () const;
    };

    class BufferManager
    {
        BufferObject vertex_buffer;

    public:
        BufferManager (const BufferObject& vertex_buffer);
    };
} // namespace Sixty::Graphics

#endif
