#include "recurring/utils/string.hpp"
#include <cstring>
#include <iostream>

namespace Recurring
{
    // I should learn how I can make constructors and assignments faster.
    // My anxiety is attacking me.

    String::String ()
    {
        // Creating an empty char, because if data==null it can lead to strange
        // stuff idk what

        size = 0;
        data = new char[size + 1];
        data[size] = '\0';
        std::cout << "->" << data << "<-" << '\n';
    }

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
        for (int i = 0; i < size; ++i)
        {
            data[i] = from.raw ()[i];
        }
    }

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
        for (int i = 0; i < size; ++i)
        {
            data[i] = from[i];
        }
    }

    String&
    String::operator= (const char* from)
    {
        delete[] data;
        size = length (from);
        data = new char[size + 1];
        for (int i = 0; i < size; ++i)
        {
            data[i] = from[i];
        }
        return *this;
    }

    String::~String ()
    {
        // Deleting data because memory leak. Obvious, and thank you for
        // reading this.
        delete[] data;
    }

    const char*
    String::raw () const
    {
        return data;
    }

    unsigned
    String::length () const
    {
        return size;
    }

    unsigned
    String::length (const char* string)
    {
        // Instead of making it doing like this, I should make it read by
        // chunks. Using, idk, something like multithread?

        unsigned size = 0;
        while (string[size] != '\0')
            ++size;
        return size;
    }

    bool
    String::compare (const String& from, const String& to)
    {
        // The option I know at this point is: check if characters of the main
        // string is the same as the compared string. This can be terrible for
        // optimization, actually. Unless I use multithread, or some kinda CPU
        // instruction. Or I can just use a standard library for this.

        return std::strcmp (from.raw (), to.raw ());
    }

    bool
    String::compare (const char* from, const char* to)
    {
        // std::strcmp sucks. If "from" equals "to" return 0.

        return std::strcmp (from, to) == 0;
    }

    bool
    String::is_empty () const
    {
        // If data doesn't exist, it's empty.

        if (data == nullptr)
            return true;

        // If data is '\0', it's empty.
        // Else, it's not empty.

        const bool is_empty = compare (data, "\0");

        return is_empty;
    }
} // namespace Recurring