#include "recurring/console/card.hpp"
#include <recurring/console/logger.hpp>

using Log = Recurring::Console::Logger;
using Card = Recurring::Console::Card;

int
main ()
{
    Log::print (Log::INFO, "Logger::print test\n");
    Log::print ("Testing it -> {}", 10);
    return 0;
}
