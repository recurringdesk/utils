#ifndef RE_UTILS_ERROR_GUARD
#define RE_UTILS_ERROR_GUARD
namespace Recurring
{
    enum Error
    {
        GLFW_NOT_INITTED = 1,
        FAILED_TO_ALLOCATE_MEMORY
    };
} // namespace Recurring
#endif // RE_UTILS_ERROR_GUARD