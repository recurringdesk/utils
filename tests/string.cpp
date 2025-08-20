#include <iostream>
#include <recurring/utils/string.hpp>

using String = Recurring::String;

int
main ()
{
    std::cout << "Testing R::string\n";
    String string = nullptr;

    std::cout << "String is now nullptr\n";

    if (string.is_empty ())
        std::cout << "string is empty\n";
    else
    {
        std::cout << "string isn't empty\n";
    }

    string = "";

    std::cout << "current string is \"" << string.raw () << "\"\n";

    if (string.is_empty ())
        std::cout << "string is empty\n";
    else
    {
        std::cout << "string isn't empty\n";
    }

    string = "Hello, world!";

    std::cout << "current string is " << string.raw () << '\n';

    if (string.is_empty ())
        std::cout << "string is empty\n";
    else
    {
        std::cout << "string isn't empty\n";
    }

    std::cout << "char at 2 -> " << string.char_at(1) << '\n';

    return 0;
}