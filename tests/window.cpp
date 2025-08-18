#include "recurring/math/functions/square_root.hpp"
#include "recurring/utils/error.hpp"
#include <recurring/math/trigonometry.hpp>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <gl/gl.h>
#include <recurring/console/logger.hpp>
#include <recurring/core/window.hpp>

using Recurring::System::Window;
using Log = Recurring::Console::Logger;
using Recurring::Core::Node;
using namespace Recurring::Math;

class MyNode : public Node
{
public:
    void
    ready () override
    {
        int value = 9;
        Log::print (Log::INFO, "sqrt of 9 == ", square_root ((float)value));
    }

    void
    process () override
    {
        // legacy opengl just for testing it - 2025-08-18

        glBegin (GL_TRIANGLES);
        glVertex2i (1, 1);
        glVertex2i (-1, -1);
        glVertex2i (1, -1);
        glEnd ();
    }
};

class MyWindow : public Window
{
protected:
    void
    internal_loop (Recurring::Core::Node* node) override
    {
        node->process ();
        swap_buffers ();
        wait_events ();
    }

public:
};

int
main ()
{

    Log::print (Log::INFO, "Hello, world!");
    MyWindow window;
    if (const int error = window.create (800, 600, "Generic window"); error != Recurring::Error::SUCCESS)
        return error;
    window.create (800, 800);
    MyNode* my_node = new MyNode;
    window.run (my_node);

    return 0;
}
