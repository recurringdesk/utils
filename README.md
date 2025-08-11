# RUtils

A C++ library for my projects.

## RLogger

Generic wrapper logger.

```cpp
#include <recurring/console/logger.hh>
using Log = Recurring::Console::Logger;

int main(void)
{
    Log::print("Hello, world!");
    return 0;
}
```

Features:

- Cards (aka tags)
- Colors
- Template

## RMath

Library for studying mathematical operations.

```cpp
#include <recurring/math/functions/square_root.hpp>
using sqrt = Recurring::Math::square_root;
int main()
{
    float x = 9;
    float x_squared = sqrt(x);
    return 0;
}
```
