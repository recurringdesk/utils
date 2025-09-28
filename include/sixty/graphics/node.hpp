#ifndef NODE_GUARD
#define NODE_GUARD

/* 64::00 | 2025-09-28 03:37:51
---
Move this to core folder
*/

namespace Sixty::Core
{
    // class Node must be like Godot's Node. Not identical, but the same ideia. - 2025-08-17

    class Node
    {
    public:
        // Idk what `virtual ~Node() = default` means. It's an empty desconstructor where
        // children classes can override it just calling their own desconstructor? - 2025-08-17

        Node () = default;
        virtual ~Node () = default;

        virtual void ready ();

        // `virtual void process()` is a function which is gonna
        // be called every time when a window is drew. - 2025-08-17

        virtual void process ();
    };
} // namespace Sixty::Core
#endif
