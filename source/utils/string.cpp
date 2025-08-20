#include <recurring/utils/string.hpp>

namespace Recurring
{
    // I should learn how I can make constructors and assignments faster.
    // My anxiety is attacking me.

    RLIB
    String::String ()
        : data (nullptr), size (0)
    {
        /*

        The next lines are horrible. Why did I do this? - 2025-08-2025

        // Creating an empty char, because if data==null it can lead to strange
        // stuff idk what

        size = 0;
        data = new char[size + 1];
        data[size] = '\0';
        */
    }

    RLIB void
    String::copy (char* to, const char* from)
    {
        int size = length (from);

        for (unsigned i = 0; i < size; ++i)
            to[i] = from[i];

        to[size] = '\0';
    }

    RLIB
    String::String (const String& from)
    {
        if (from.raw () == nullptr)
        {
            size = 0;
            data = new char[size + 1];
            data[size] = '\0';
            return;
        }
        size = length (from.raw ());
        data = new char[size + 1];

        copy (data, from.raw ());
    }

    RLIB
    String::String (const char* from)
    {
        if (from == nullptr)
        {
            size = 0;
            data = new char[size + 1];
            data[size] = '\0';
            return;
        }
        size = length (from);
        data = new char[size + 1];
        copy (data, from);
    }

    RLIB String&
    String::operator= (const char* from)
    {
        delete[] data;
        size = length (from);
        data = new char[size + 1];
        copy (data, from);
        return *this;
    }

    RLIB String::~String ()
    {
        // Deleting data because memory leak. Obvious, and thank you for
        // reading this.
        delete[] data;
    }

    RLIB const char*
    String::raw () const
    {
        return data;
    }

    RLIB unsigned
    String::length () const
    {
        return size;
    }

    RLIB unsigned
    String::length (const char* string)
    {
        // Instead of making it doing like this, I should make it read by
        // chunks. Using, idk, something like multithread?

        if (!string)
            return 0;
        unsigned size = 0;
        while (string[size] != '\0')
            ++size;
        return size;
    }

    bool
    String::operator!() const
    {
        // If data doesn't exist or the first element is '\0', return false.


        return data == nullptr || data[0] == '\0';
    }

    bool
    String::compare (const String& from, const String& to)
    {
        // The option I know at this point is: check if characters of the main
        // string is the same as the compared string. This can be terrible for
        // optimization, actually. Unless I use multithread, or some kinda CPU
        // instruction. Or I can just use a standard library for this.

        if (!from || !to)
            return false;

        for (int index = 0; from.raw ()[index] != '\0'; ++index)
            if (from.raw ()[index] != to.raw ()[index])
                return false;

        return true;
    }

    bool
    String::compare (const char* from, const char* to)
    {
        // std::strcmp sucks. If "from" equals "to" return 0.

        if (!from || !to)
            return false;

        for (int index = 0; from[index] != '\0'; ++index)
            if (from[index] != to[index])
                return false;

        return true;
    }

    bool
    String::is_empty () const
    {
        /*
        The next code in this comment is redundant.
        compare sends a false signal if data is nullptr, why
        am I double checking this? - 2025-08-20

        // If data doesn't exist, it's empty.

        if (data == nullptr)
            return true;

        // If data is '\0', it's empty.
        // Else, it's not empty.

        */

        // If data's nullptr or "", return false.
        // else, it's ROGER. - 2025-08-25
        const bool is_empty = compare (data, "");

        return is_empty;
    }

    RLIB char&
    String::char_at (unsigned int position) const
    {
        return data[position];
    }
} // namespace Recurring