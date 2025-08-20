#ifndef RE_UTILS_STRING_GUARD
#define RE_UTILS_STRING_GUARD

#include <recurring/utils/api.hpp>

namespace Recurring
{
    // A substitute for std::string and blah blah blah.
    // Try to use it in the whole project! - 2025-08-17

    class RLIB String
    {
    public:
        String ();
        String (const char* from);
        String (const String& from);
        ~String ();

        static void copy (char* to, const char* from);

        String& operator= (const char* from);
        bool operator!() const;

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

        // I need to implement this. It's kinda simple. - 2025-08-17

        void push_back (const char* from);
        void push_back (const String& from);

        char& char_at (unsigned int position) const;

    private:
        // The real and current storaged data. - 2025-08-17
        char* data;
        // The string's size. Not needing to recalculate
        // stuff every time when calling `length` - 2025-08-17
        unsigned size;
    };
} // namespace Recurring

#endif // RE_UTILS_STRING_GUARD