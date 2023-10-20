#pragma once
#include "/Users/josephmcilvaine/cpp-cross-platform/include/Input.h"
using namespace mr::Input;
namespace mr::RobotImpl
{
   	void KeyPress(GlobalKeyEvent e);

	void KeyRelease(GlobalKeyEvent e);

	void MouseMove(GlobalMouseEvent e);

	void MousePress(GlobalMouseEvent e);

	void MouseRelease(GlobalMouseEvent e); 
}