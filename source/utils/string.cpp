#include "recurring/utils/string.hpp"
#include <cstring>

namespace Recurring
{
    String::String ()
    {
        // Creating an empty char, because if data==null it can lead to strange
        // stuff idk what
        data = new char[0];
        data[0] = '\0';
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
        unsigned size = 0;
        while (string[size] != '\0')
            ++size;
        return size;
    }

    bool
    String::compare (const String& with) const
    {
        // The option I know at this point is: check if characters of the main
        // string is the same as the compared string. This can be terrible for
        // optimization, actually. Unless I use multithread, or some kinda CPU
        // instruction. Or I just use a standard library for this.
        return std::memcmp (data, with.raw (), size);
    }

    bool
    String::empty () const
    {
        if (data == nullptr)
        {
            return false;
        }
        else if (compare (""))
        {
            return false;
        }
        else
        {
            return true;
        }
    }
} // namespace Recurring