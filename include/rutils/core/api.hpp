#ifndef RE_API_GUARD
#define RE_API_GUARD

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

#endif // RE_API_GUARD