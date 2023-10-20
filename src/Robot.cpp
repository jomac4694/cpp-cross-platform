#include "/Users/josephmcilvaine/cpp-cross-platform/include/RobotImpl.h"


namespace mr
{
    void Input::KeyBoard::KeyPress(GlobalKeyEvent e)
    {
        RobotImpl::KeyPress(e);
    }

    void Input::KeyBoard::KeyRelease(GlobalKeyEvent e)
    {
        RobotImpl::KeyRelease(e);
    }

    void Input::Mouse::MouseMove(GlobalMouseEvent e)
    {
        RobotImpl::MouseMove(e);
    }

    void Input::Mouse::MousePress(GlobalMouseEvent e)
    {
        RobotImpl::MousePress(e);
    }

    void Input::Mouse::MouseRelease(GlobalMouseEvent e)
    {
        RobotImpl::MouseRelease(e);
    }
}