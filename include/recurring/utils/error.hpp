#ifndef RE_UTILS_ERROR_GUARD
#define RE_UTILS_ERROR_GUARD

namespace Recurring
{
    // Errors codes
    // Just avoiding magic numbers. - 2025-08-17

    enum Error
    {
        SUCCESS = 0,
        GLFW_NOT_INITED,
        GLEW_NOT_INITED,
        OPENGL_NOT_LOADED,
        MEMORY_NOT_ALLOCATED,
        WINDOW_ALREADY_EXISTS,
        NO_WINDOW_TO_LOOP,
        NO_WINDOW_TO_DESTROY,
        NO_WINDOW_TO_SET_FRAMEBUFFER_SIZE_CALLBACK,
        CONTEXT_WAS_NOT_MAKE,
        STRING_IS_EMPTY
    };
} // namespace Recurring
#endif // RE_UTILS_ERROR_GUARD