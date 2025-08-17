#include <glad/glad.h>

#include <recurring/console/logger.hpp>
#include <recurring/core/window.hpp>

using Recurring::System::Window;
using Log = Recurring::Console::Logger;
using Recurring::Core::Node;
using Recurring::System::MainLoop;

class GameScene : public Node
{
public:
    void
    ready () override
    {
    }

    void
    process () override
    {
    }
};

int
main ()
{

    Log::print (Log::INFO, "Hello, world!");
    Window window;
    window.create (800, 600);
    GameScene game_scene;
    MainLoop main_loop (window, game_scene);
    main_loop.run ();

    return 0;
}