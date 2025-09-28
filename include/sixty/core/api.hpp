#ifndef API_GUARD
#define API_GUARD

/* 64::00 | 2025-08-27 15:15:29
---
This is the original code.

----

// This header exist because Windows is the worst OS I've ever used. - 2025-08-17

#ifdef _WIN32
#ifdef RLIB_EXPORT
#define RLIB __declspec (dllexport)
#else
#define RLIB __declspec (dllimport)
#endif
#else
#define RLIB
#endif

----

Decided to remove it and use a cmake command to make compile time easier.

I didn't test it in Windows, so... Idk if this is working or not.
*/

#endif
