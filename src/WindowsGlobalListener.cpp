#include "WindowsGlobalListener.h"
#include <Windows.h>
#include <windowsx.h>
#include <chrono>
#include <iostream>
#include "RobotFactory.h"
using namespace mr;
extern std::shared_ptr<Recording> mRecording;
namespace 
{
    Input::KeyBoard::Key virtualKeyToInputKey(UINT virtualKey)
    {
        // clang-format off
        switch (virtualKey)
        {
        case 'A':           return Input::KeyBoard::A;
        case 'B':           return Input::KeyBoard::B;
        case 'C':           return Input::KeyBoard::C;
        case 'D':           return Input::KeyBoard::D;
        case 'E':           return Input::KeyBoard::E;
        case 'F':           return Input::KeyBoard::F;
        case 'G':           return Input::KeyBoard::G;
        case 'H':           return Input::KeyBoard::H;
        case 'I':           return Input::KeyBoard::I;
        case 'J':           return Input::KeyBoard::J;
        case 'K':           return Input::KeyBoard::K;
        case 'L':           return Input::KeyBoard::L;
        case 'M':           return Input::KeyBoard::M;
        case 'N':           return Input::KeyBoard::N;
        case 'O':           return Input::KeyBoard::O;
        case 'P':           return Input::KeyBoard::P;
        case 'Q':           return Input::KeyBoard::Q;
        case 'R':           return Input::KeyBoard::R;
        case 'S':           return Input::KeyBoard::S;
        case 'T':           return Input::KeyBoard::T;
        case 'U':           return Input::KeyBoard::U;
        case 'V':           return Input::KeyBoard::V;
        case 'W':           return Input::KeyBoard::W;
        case 'X':           return Input::KeyBoard::X;
        case 'Y':           return Input::KeyBoard::Y;
        case 'Z':           return Input::KeyBoard::Z;
        case '0':           return Input::KeyBoard::Num0;
        case '1':           return Input::KeyBoard::Num1;
        case '2':           return Input::KeyBoard::Num2;
        case '3':           return Input::KeyBoard::Num3;
        case '4':           return Input::KeyBoard::Num4;
        case '5':           return Input::KeyBoard::Num5;
        case '6':           return Input::KeyBoard::Num6;
        case '7':           return Input::KeyBoard::Num7;
        case '8':           return Input::KeyBoard::Num8;
        case '9':           return Input::KeyBoard::Num9;
        case VK_ESCAPE:     return Input::KeyBoard::Escape;
        case VK_LCONTROL:   return Input::KeyBoard::LControl;
        case VK_LSHIFT:     return Input::KeyBoard::LShift;
        case VK_LMENU:      return Input::KeyBoard::LAlt;
        case VK_LWIN:       return Input::KeyBoard::LSystem;
        case VK_RCONTROL:   return Input::KeyBoard::RControl;
        case VK_RSHIFT:     return Input::KeyBoard::RShift;
        case VK_RMENU:      return Input::KeyBoard::RAlt;
        case VK_RWIN:       return Input::KeyBoard::RSystem;
        case VK_APPS:       return Input::KeyBoard::Menu;
        case VK_OEM_4:      return Input::KeyBoard::LBracket;
        case VK_OEM_6:      return Input::KeyBoard::RBracket;
        case VK_OEM_1:      return Input::KeyBoard::Semicolon;
        case VK_OEM_COMMA:  return Input::KeyBoard::Comma;
        case VK_OEM_PERIOD: return Input::KeyBoard::Period;
        case VK_OEM_7:      return Input::KeyBoard::Apostrophe;
        case VK_OEM_2:      return Input::KeyBoard::Slash;
        case VK_OEM_5:      return Input::KeyBoard::Backslash;
        case VK_OEM_3:      return Input::KeyBoard::Grave;
        case VK_OEM_PLUS:   return Input::KeyBoard::Equal;
        case VK_OEM_MINUS:  return Input::KeyBoard::Hyphen;
        case VK_SPACE:      return Input::KeyBoard::Space;
        case VK_RETURN:     return Input::KeyBoard::Enter;
        case VK_BACK:       return Input::KeyBoard::Backspace;
        case VK_TAB:        return Input::KeyBoard::Tab;
        case VK_PRIOR:      return Input::KeyBoard::PageUp;
        case VK_NEXT:       return Input::KeyBoard::PageDown;
        case VK_END:        return Input::KeyBoard::End;
        case VK_HOME:       return Input::KeyBoard::Home;
        case VK_INSERT:     return Input::KeyBoard::Insert;
        case VK_DELETE:     return Input::KeyBoard::Delete;
        case VK_ADD:        return Input::KeyBoard::Add;
        case VK_SUBTRACT:   return Input::KeyBoard::Subtract;
        case VK_MULTIPLY:   return Input::KeyBoard::Multiply;
        case VK_DIVIDE:     return Input::KeyBoard::Divide;
        case VK_LEFT:       return Input::KeyBoard::Left;
        case VK_RIGHT:      return Input::KeyBoard::Right;
        case VK_UP:         return Input::KeyBoard::Up;
        case VK_DOWN:       return Input::KeyBoard::Down;
        case VK_NUMPAD0:    return Input::KeyBoard::Numpad0;
        case VK_NUMPAD1:    return Input::KeyBoard::Numpad1;
        case VK_NUMPAD2:    return Input::KeyBoard::Numpad2;
        case VK_NUMPAD3:    return Input::KeyBoard::Numpad3;
        case VK_NUMPAD4:    return Input::KeyBoard::Numpad4;
        case VK_NUMPAD5:    return Input::KeyBoard::Numpad5;
        case VK_NUMPAD6:    return Input::KeyBoard::Numpad6;
        case VK_NUMPAD7:    return Input::KeyBoard::Numpad7;
        case VK_NUMPAD8:    return Input::KeyBoard::Numpad8;
        case VK_NUMPAD9:    return Input::KeyBoard::Numpad9;
        case VK_F1:         return Input::KeyBoard::F1;
        case VK_F2:         return Input::KeyBoard::F2;
        case VK_F3:         return Input::KeyBoard::F3;
        case VK_F4:         return Input::KeyBoard::F4;
        case VK_F5:         return Input::KeyBoard::F5;
        case VK_F6:         return Input::KeyBoard::F6;
        case VK_F7:         return Input::KeyBoard::F7;
        case VK_F8:         return Input::KeyBoard::F8;
        case VK_F9:         return Input::KeyBoard::F9;
        case VK_F10:        return Input::KeyBoard::F10;
        case VK_F11:        return Input::KeyBoard::F11;
        case VK_F12:        return Input::KeyBoard::F12;
        case VK_F13:        return Input::KeyBoard::F13;
        case VK_F14:        return Input::KeyBoard::F14;
        case VK_F15:        return Input::KeyBoard::F15;
        case VK_PAUSE:      return Input::KeyBoard::Pause;
        default:            return Input::KeyBoard::Unknown;
        }
        // clang-format on
    }

	HHOOK _Keyboardhook;
	HHOOK _Mousehook;

	// This struct contains the data received by the hook callback. As you see in the callback function
	// it contains the thing you will need: vkCode = virtual key code.
	KBDLLHOOKSTRUCT kbdStruct;





	void ReleaseHook()
	{
		UnhookWindowsHookEx(_Keyboardhook);
		UnhookWindowsHookEx(_Mousehook);
	}
}
WindowsGlobalListener::WindowsGlobalListener()
{

}

// This is the callback function. Consider it the event that is raised when, in this case, 
// a key is pressed.
LRESULT __stdcall WindowsGlobalListener::MouseCallback(int nCode, WPARAM wParam, LPARAM lParam)
{
    static int mouse_move_count = 0;

	if (nCode >= 0)
	{
        Input::GlobalMouseEvent m = {};
        MSLLHOOKSTRUCT* pMouseStruct = (MSLLHOOKSTRUCT*)lParam;
		switch (wParam)
		{
		case WM_LBUTTONDOWN:
            m.action = Input::Mouse::PRESS;
            m.button = Input::Mouse::Left;
            m.timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
            mRecording->push_back(std::shared_ptr<PlaybackAction>(new MouseAction(m)));
			break;
        case WM_LBUTTONUP:
            m.action = Input::Mouse::RELEASE;
            m.button = Input::Mouse::Left;
            m.timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
            mRecording->push_back(std::shared_ptr<PlaybackAction>(new MouseAction(m)));
            break;
        case WM_RBUTTONDOWN:
            m.action = Input::Mouse::PRESS;
            m.button = Input::Mouse::Right;
            m.timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
            mRecording->push_back(std::shared_ptr<PlaybackAction>(new MouseAction(m)));
            break;
        case WM_RBUTTONUP:
            m.action = Input::Mouse::RELEASE;
            m.button = Input::Mouse::Right;
            m.timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
            mRecording->push_back(std::shared_ptr<PlaybackAction>(new MouseAction(m)));
            break;
		case WM_MOUSEMOVE:
			auto xPos = pMouseStruct->pt.x;
			auto yPos = pMouseStruct->pt.y;
			m.action = Input::Mouse::Action::MOVE;
			m.x = xPos;
			m.y = yPos;
            m.timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
           // std::cout << "x=" << m.x <<std::endl;
          //  std::cout << "y=" << m.y << std::endl;
           // std::cout << "timestamp=" << m.timestamp << std::endl;
            mRecording->push_back(std::shared_ptr<PlaybackAction>(new MouseAction(m)));
            mouse_move_count++;
            if (mouse_move_count == 5000)
            {
               // std::cout << "heyo" << std::endl;
                PostThreadMessageA(GetCurrentThreadId(), 0, wParam, lParam);
            }
			break;
		}

	}

	// call the next hook in the hook chain. This is nessecary or your hook chain will break and the hook stops
	return CallNextHookEx(_Mousehook, nCode, wParam, lParam);
}

LRESULT __stdcall WindowsGlobalListener::KeyboardCallback(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (nCode >= 0)
	{
		// the action is valid: HC_ACTION.
		if (wParam == WM_KEYDOWN)
		{
			// lParam is the pointer to the struct containing the data needed, so cast and assign it to kdbStruct.
			kbdStruct = *((KBDLLHOOKSTRUCT*)lParam);
            Input::GlobalKeyEvent e;
            e.key = virtualKeyToInputKey(kbdStruct.vkCode);
            e.action = Input::KeyBoard::PRESS;
            e.timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
            mRecording->push_back(std::shared_ptr<PlaybackAction>(new KeyboardAction(e)));
		}
        else if (wParam == WM_KEYUP)
        {
            kbdStruct = *((KBDLLHOOKSTRUCT*)lParam);
            Input::GlobalKeyEvent e;
            e.key = virtualKeyToInputKey(kbdStruct.vkCode);
            e.action = Input::KeyBoard::RELEASE;
            e.timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
            mRecording->push_back(std::shared_ptr<PlaybackAction>(new KeyboardAction(e)));

        }
	}

	// call the next hook in the hook chain. This is nessecary or your hook chain will break and the hook stops
	return CallNextHookEx(_Keyboardhook, nCode, wParam, lParam);
}

void WindowsGlobalListener::SetHook()
{
	// Set the hook and set it to use the callback function above
	// WH_KEYBOARD_LL means it will set a low level keyboard hook. More information about it at MSDN.
	// The last 2 parameters are NULL, 0 because the callback function is in the same thread and window as the
	// function that sets and releases the hook. If you create a hack you will not need the callback function 
	// in another place then your own code file anyway. Read more about it at MSDN.
	if (!(_Keyboardhook = SetWindowsHookEx(WH_KEYBOARD_LL, WindowsGlobalListener::KeyboardCallback, NULL, 0)))
	{
		//MessageBox(NULL, (LPCWSTR)"Failed to install hook!", (LPCWSTR)"Error", MB_ICONERROR);
	}
	if (!(_Mousehook = SetWindowsHookEx(WH_MOUSE_LL, WindowsGlobalListener::MouseCallback, NULL, 0)))
	{
		//MessageBox(NULL, (LPCWSTR)"Failed to install hook!", (LPCWSTR)"Error", MB_ICONERROR);
	}
}
void WindowsGlobalListener::Start()
{
	SetHook();
}

void WindowsGlobalListener::Stop()
{
	ReleaseHook();
}
