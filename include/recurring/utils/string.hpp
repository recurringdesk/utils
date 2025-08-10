#pragma once

namespace Recurring
{
    // @todo Move String to a new header file
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

        bool empty () const;

        /**
         * @brief Returns the purest form of a string in C++
         *
         * @return const char*
         */
        const char* raw () const;

        unsigned length () const;
        static unsigned length (const char* string);

        /**
         * @brief Compares a string with another
         *
         * @param with
         * @return true
         * @return false
         */
        bool compare (const String& with) const;
        bool compare (const char* with) const;

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