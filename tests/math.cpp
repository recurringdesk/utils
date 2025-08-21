#include <recurring/console/logger.hpp>
#include <recurring/math/functions/basic.hpp>

using Recurring::Console::Logger;
using namespace Recurring;

int
main ()
{
    Logger::print (Math::pow (4.0f, 2.0f));
    return 0;
}