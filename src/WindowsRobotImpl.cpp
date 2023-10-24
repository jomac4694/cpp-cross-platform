//#include "WindowsRobotImpl.h"
#include "RobotImpl.h"
#include "Windows.h"
#include <iostream>
namespace mr
{
    int sfKeyToVirtualKey(Input::KeyBoard::Key key)
    {
        // clang-format off
        switch (key)
        {
        case Input::KeyBoard::A:          return 'A';
        case Input::KeyBoard::B:          return 'B';
        case Input::KeyBoard::C:          return 'C';
        case Input::KeyBoard::D:          return 'D';
        case Input::KeyBoard::E:          return 'E';
        case Input::KeyBoard::F:          return 'F';
        case Input::KeyBoard::G:          return 'G';
        case Input::KeyBoard::H:          return 'H';
        case Input::KeyBoard::I:          return 'I';
        case Input::KeyBoard::J:          return 'J';
        case Input::KeyBoard::K:          return 'K';
        case Input::KeyBoard::L:          return 'L';
        case Input::KeyBoard::M:          return 'M';
        case Input::KeyBoard::N:          return 'N';
        case Input::KeyBoard::O:          return 'O';
        case Input::KeyBoard::P:          return 'P';
        case Input::KeyBoard::Q:          return 'Q';
        case Input::KeyBoard::R:          return 'R';
        case Input::KeyBoard::S:          return 'S';
        case Input::KeyBoard::T:          return 'T';
        case Input::KeyBoard::U:          return 'U';
        case Input::KeyBoard::V:          return 'V';
        case Input::KeyBoard::W:          return 'W';
        case Input::KeyBoard::X:          return 'X';
        case Input::KeyBoard::Y:          return 'Y';
        case Input::KeyBoard::Z:          return 'Z';
        case Input::KeyBoard::Num0:       return '0';
        case Input::KeyBoard::Num1:       return '1';
        case Input::KeyBoard::Num2:       return '2';
        case Input::KeyBoard::Num3:       return '3';
        case Input::KeyBoard::Num4:       return '4';
        case Input::KeyBoard::Num5:       return '5';
        case Input::KeyBoard::Num6:       return '6';
        case Input::KeyBoard::Num7:       return '7';
        case Input::KeyBoard::Num8:       return '8';
        case Input::KeyBoard::Num9:       return '9';
        case Input::KeyBoard::Escape:     return VK_ESCAPE;
        case Input::KeyBoard::LControl:   return VK_LCONTROL;
        case Input::KeyBoard::LShift:     return VK_LSHIFT;
        case Input::KeyBoard::LAlt:       return VK_LMENU;
        case Input::KeyBoard::LSystem:    return VK_LWIN;
        case Input::KeyBoard::RControl:   return VK_RCONTROL;
        case Input::KeyBoard::RShift:     return VK_RSHIFT;
        case Input::KeyBoard::RAlt:       return VK_RMENU;
        case Input::KeyBoard::RSystem:    return VK_RWIN;
        case Input::KeyBoard::Menu:       return VK_APPS;
        case Input::KeyBoard::LBracket:   return VK_OEM_4;
        case Input::KeyBoard::RBracket:   return VK_OEM_6;
        case Input::KeyBoard::Semicolon:  return VK_OEM_1;
        case Input::KeyBoard::Comma:      return VK_OEM_COMMA;
        case Input::KeyBoard::Period:     return VK_OEM_PERIOD;
        case Input::KeyBoard::Apostrophe: return VK_OEM_7;
        case Input::KeyBoard::Slash:      return VK_OEM_2;
        case Input::KeyBoard::Backslash:  return VK_OEM_5;
        case Input::KeyBoard::Grave:      return VK_OEM_3;
        case Input::KeyBoard::Equal:      return VK_OEM_PLUS;
        case Input::KeyBoard::Hyphen:     return VK_OEM_MINUS;
        case Input::KeyBoard::Space:      return VK_SPACE;
        case Input::KeyBoard::Enter:      return VK_RETURN;
        case Input::KeyBoard::Backspace:  return VK_BACK;
        case Input::KeyBoard::Tab:        return VK_TAB;
        case Input::KeyBoard::PageUp:     return VK_PRIOR;
        case Input::KeyBoard::PageDown:   return VK_NEXT;
        case Input::KeyBoard::End:        return VK_END;
        case Input::KeyBoard::Home:       return VK_HOME;
        case Input::KeyBoard::Insert:     return VK_INSERT;
        case Input::KeyBoard::Delete:     return VK_DELETE;
        case Input::KeyBoard::Add:        return VK_ADD;
        case Input::KeyBoard::Subtract:   return VK_SUBTRACT;
        case Input::KeyBoard::Multiply:   return VK_MULTIPLY;
        case Input::KeyBoard::Divide:     return VK_DIVIDE;
        case Input::KeyBoard::Left:       return VK_LEFT;
        case Input::KeyBoard::Right:      return VK_RIGHT;
        case Input::KeyBoard::Up:         return VK_UP;
        case Input::KeyBoard::Down:       return VK_DOWN;
        case Input::KeyBoard::Numpad0:    return VK_NUMPAD0;
        case Input::KeyBoard::Numpad1:    return VK_NUMPAD1;
        case Input::KeyBoard::Numpad2:    return VK_NUMPAD2;
        case Input::KeyBoard::Numpad3:    return VK_NUMPAD3;
        case Input::KeyBoard::Numpad4:    return VK_NUMPAD4;
        case Input::KeyBoard::Numpad5:    return VK_NUMPAD5;
        case Input::KeyBoard::Numpad6:    return VK_NUMPAD6;
        case Input::KeyBoard::Numpad7:    return VK_NUMPAD7;
        case Input::KeyBoard::Numpad8:    return VK_NUMPAD8;
        case Input::KeyBoard::Numpad9:    return VK_NUMPAD9;
        case Input::KeyBoard::F1:         return VK_F1;
        case Input::KeyBoard::F2:         return VK_F2;
        case Input::KeyBoard::F3:         return VK_F3;
        case Input::KeyBoard::F4:         return VK_F4;
        case Input::KeyBoard::F5:         return VK_F5;
        case Input::KeyBoard::F6:         return VK_F6;
        case Input::KeyBoard::F7:         return VK_F7;
        case Input::KeyBoard::F8:         return VK_F8;
        case Input::KeyBoard::F9:         return VK_F9;
        case Input::KeyBoard::F10:        return VK_F10;
        case Input::KeyBoard::F11:        return VK_F11;
        case Input::KeyBoard::F12:        return VK_F12;
        case Input::KeyBoard::F13:        return VK_F13;
        case Input::KeyBoard::F14:        return VK_F14;
        case Input::KeyBoard::F15:        return VK_F15;
        case Input::KeyBoard::Pause:      return VK_PAUSE;
        default:                   return 0;
        }
        // clang-format on
    }
}
namespace mr::RobotImpl
{
void KeyPress(GlobalKeyEvent e)
{
    INPUT input[1] = { 0 };
    input[0].type = INPUT_KEYBOARD;
    input[0].ki.wVk = sfKeyToVirtualKey(e.key);
    input[0].ki.wScan = 0;
    input[0].ki.dwFlags = 0;
    input[0].ki.time = 0;
    input[0].ki.dwExtraInfo = GetMessageExtraInfo();
    UINT sent = SendInput(1, input, sizeof(INPUT));
    if (sent != ARRAYSIZE(input))
    {
        std::cout << HRESULT_FROM_WIN32(GetLastError()) << std::endl;
    }
}

void KeyRelease(GlobalKeyEvent e)
{
    INPUT input[1] = { 0 };
    input[0].type = INPUT_KEYBOARD;
    input[0].ki.wVk = sfKeyToVirtualKey(e.key);
    input[0].ki.wScan = 0;
    input[0].ki.dwFlags = KEYEVENTF_KEYUP;
    input[0].ki.time = 0;
    input[0].ki.dwExtraInfo = GetMessageExtraInfo();
    UINT sent = SendInput(1, input, sizeof(INPUT));
    if (sent != ARRAYSIZE(input))
    {
        std::cout << HRESULT_FROM_WIN32(GetLastError()) << std::endl;
    }
}

void MouseMove(GlobalMouseEvent e)
{
    /*
    POINT p;
    GetCursorPos(&p);
    std::cout << "GetCursorPos x=" << p.x << ",y=" << p.y << std::endl;
    if (p.x == e.x && p.y == e.y)
    {
        std::cout << "Not setting the same position" << std::endl;
        return;
    }
   
    if (SetCursorPos(e.x, e.y) == 0)
        std::cout << "SetCursorPos failed, not good" << std::endl;
   */
    
    INPUT input;
    input.type = INPUT_MOUSE;
    input.mi.time = 0;
    input.mi.dx = e.x * (65536 / GetSystemMetrics(SM_CXSCREEN));
    input.mi.dy = e.y * (65536 / GetSystemMetrics(SM_CYSCREEN));
    input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE_NOCOALESCE;
    SendInput(1, &input, sizeof(input));
    
}

void MousePress(GlobalMouseEvent e)
{
	INPUT input[1] = { 0 };
	input[0].type = INPUT_MOUSE;
	input[0].mi.dwFlags = e.button == Input::Mouse::Left ? MOUSEEVENTF_LEFTDOWN : MOUSEEVENTF_RIGHTDOWN;
    UINT sent = SendInput(1, input, sizeof(INPUT));
    if (sent != ARRAYSIZE(input))
    {
        std::cout << HRESULT_FROM_WIN32(GetLastError()) << std::endl;
    }
}

void MouseRelease(GlobalMouseEvent e)
{
	INPUT input[1] = { 0 };
	input[0].type = INPUT_MOUSE;
	input[0].mi.dwFlags = e.button == Input::Mouse::Left ? MOUSEEVENTF_LEFTUP : MOUSEEVENTF_RIGHTUP;
	UINT sent = SendInput(1, input, sizeof(INPUT));
    if (sent != ARRAYSIZE(input))
    {
        std::cout << HRESULT_FROM_WIN32(GetLastError()) << std::endl;
    }
}
}