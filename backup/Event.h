
#include <chrono>
#include "/Users/josephmcilvaine/cpp-cross-platform/include/Input.h"
namespace mr
{
    namespace Event
    {
        struct GlobalEvent
        {
        };

        struct GlobalMouseEvent : GlobalEvent
        {
            std::time_t timestamp;
            int x;
            int y;
            Mouse::Action action;
            Input::Mouse::Button button;
        };

        struct GlobalKeyEvent : GlobalEvent
        {
            std::time_t timestamp;
            KeyBoard::Action action;
            Input::KeyBoard::Key key;
        };
    }
}