#include <glad/glad.h>
#include <recurring/console/logger.hpp>
#include <recurring/core/window.hpp>
using Recurring::System::Window;
using Log = Recurring::Console::Logger;
using Recurring::System::MainLoop;
using Recurring::Core::Node;

class GameScene : public Node
{
public:
    void
    process () override
    {
        Log::print("OK");
    }
};

int
main ()
{
    Window window;
    window.create (800, 600);
    GameScene game_scene;
    MainLoop main_loop (window, game_scene);
    main_loop.run ();

    return 0;
}