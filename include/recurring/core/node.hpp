#ifndef RE_NODE_GUARD
#define RE_NODE_GUARD

#include <recurring/utils/api.hpp>

namespace Recurring::Core
{
    class RLIB Node
    {
    public:
        Node () = default;
        virtual ~Node () = default;

        virtual void
        ready ()
        {
        }

        virtual void
        process ()
        {
        }
    };
} // namespace Recurring::Core
#endif // RE_NODE_GUARD