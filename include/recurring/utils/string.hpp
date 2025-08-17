#ifndef RE_UTILS_STRING_GUARD
#define RE_UTILS_STRING_GUARD

#include <recurring/utils/api.hpp>

namespace Recurring
{
    struct RLIB String
    {
        String ();
        String (const char* from);
        String (const String& from);
        ~String ();

        String& operator= (const char* from);

        bool is_empty () const;

        /**
         * @brief Returns the purest form of a string in C++
         *
         * @return const char*
         */
        const char* raw () const;

        unsigned length () const;
        static unsigned length (const char* string);

        /**
         * @brief Compares a string to another
         *
         * @return true
         * @return false
         */
        static bool compare (const char* from, const char* to);
        static bool compare (const String& from, const String& to);

        // @todo Implement push_back
        void push_back (const char* from);
        void push_back (const String& from);

    private:
        char* data = nullptr;
        unsigned size = 0;
    };
} // namespace Recurring

#endif // RE_UTILS_STRING_GUARD