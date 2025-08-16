#include <recurring/core/buffer_manager.hpp>

namespace Recurring::Core::Graphics
{
    BufferManager::BufferManager (const BufferObject& vertex_buffer)
        : vertex_buffer (vertex_buffer)
    {
    }

    BufferObject::BufferObject (GLenum target, GLenum usage, GLsizeiptr size)
    {
        this->target = target;
        this->size = size;
        this->usage = usage;

        glGenBuffers (1, &id);
        glBindBuffer (target, id);
        glBufferData (target, size, &id, usage);
    }

    BufferObject::~BufferObject ()
    {
        if (!id)
            return;
        glDeleteBuffers (1, &id);
    }

    void
    BufferObject::bind () const
    {
        glBindBuffer (target, id);
    }

    void
    BufferObject::unbind () const
    {
        glBindBuffer (target, 0);
    }

} // namespace Recurring::Core::Graphics