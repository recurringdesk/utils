#ifndef RE_API_GUARD
#define RE_API_GUARD

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