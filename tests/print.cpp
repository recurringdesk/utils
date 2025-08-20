#include "recurring/console/card.hpp"
#include "recurring/math/objects/vector2d.hpp"
#include <recurring/console/logger.hpp>

using Log = Recurring::Console::Logger;
using Card = Recurring::Console::Card;

int
main ()
{
    Log::print (Log::INFO, "Logger::print test");
    Log::print ("Testing it -> ", 10);

    Recurring::Math::Vector2D vector;

    // This must give you an error
    // Log::print (Log::INFO, "Vector -> ", vector);
    return 0;
}
