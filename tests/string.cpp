#include <iostream>
#include <recurring/utils/string.hpp>

using String = Recurring::String;

int
main ()
{
    std::cout << "Testing R::string\n";
    String string = "";

    std::cout << "current string is \'\\0\'\n";

    if (string.is_empty ())
        std::cout << "OK\n";
    else
    {
        std::cout << "OKNOTOK\n";
        return 1;
    }

    string = "Hello, world!";

    std::cout << "current string is " << string.raw ();

    return 0;
}