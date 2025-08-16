#include <iostream>
#include <recurring/console/logger.hpp>
using Log = Recurring::Console::Logger;

int
main ()
{
    bool activate_debug;
    std::cin >> activate_debug;
    Log::debug_mode = activate_debug;
    int code = 30;

    Log::print (Log::DEBUG, "The secret code is {}", code);
    if (Log::debug_mode == true)
    {
        Log::print (Log::INFO, "ENABLED");
    }
    else
    {
        Log::print (Log::INFO, "If you see the 'secret code' above, this sucks");
        Log::print (Log::INFO, "DISABLED");
    }

    return 0;
}