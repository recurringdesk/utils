# ReUtils

A C++ library in development for my projects and studies.

> [!IMPORTANT]
> ReUtils uses nested namespaces and tries to enforce strong encapsulation. Avoiding the use of standard libraries in header files is somewhat difficult and may even be a bad design.

# ReConsole

Terminal utilities!

## ReLogger

Wrapper for `std::print` but with "cards" - cards are tags for messages.

```cpp
#include <recurring/console/logger.hpp>

using Log = Recurring::Console::Logger;

int
main ()
{
    Log::print (Log::INFO, "Hello, world!");
    return 0;
}
```

# ReMath

A wrapper library for cmath with extras. Ugly, but it works.

```cpp
#include <recurring/console/logger.hpp>
#include <recurring/math/trigonometry.hpp>

using namespace Recurring::Math;
using Log = Recurring::Console::Logger;

int
main ()
{
    float distance = 10.0f;
    float angle = degrees_to_radians (45.0f);
    float horizontal = distance * cosine (angle);

    Log::print (Log::INFO, "Horizontal -> {}", horizontal);

    return 0;
}
```