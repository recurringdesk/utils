#include <iostream>
#include <recurring/utils/string.hpp>

using String = Recurring::String;

int
main ()
{
    std::cout << "Testing R::string\n";
    String string = "";

    std::cout << "current string is \"\"\n";

    if (string.is_empty ())
        std::cout << "string is empty\n";
    else
    {
        std::cout << "string isn't empty\n";
    }

    string = "Hello, world!";

    std::cout << "current string is " << string.raw () << '\n';

    return 0;
}