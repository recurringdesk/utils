#ifndef RE_CORE_BF_MNGR_GUARD
#define RE_CORE_BF_MNGR_GUARD

#include <GL/glew.h>
#include <rutils/core/api.hpp>

namespace Recurring::Core::Graphics
{
    struct RLIB BufferObject
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

    class RLIB BufferManager
    {
        BufferObject vertex_buffer;

    public:
        BufferManager (const BufferObject& vertex_buffer);
    };
} // namespace Recurring::Core::Graphics

#endif // RE_CORE_BF_MNGR_GUARD