#pragma once

namespace Recurring
{
    struct String
    {
      private:
        char* data = nullptr;
        unsigned size = 0;

      public:
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

        template <typename... T>
        static String
        format (const String& string, T... args)
        {
            return "";
        }
    };
} // namespace Recurring