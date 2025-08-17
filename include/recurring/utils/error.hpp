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
        OPENGL_NOT_LOADED,
        MEMORY_NOT_ALLOCATED,
        NO_WINDOW_TO_LOOP,
        CONTEXT_WAS_NOT_MAKE
    };
} // namespace Recurring
#endif // RE_UTILS_ERROR_GUARD