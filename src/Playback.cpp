#include "Playback.h"
#include "Input.h"
#include "Playback.h"
#include <thread>
#include <iostream>
#include "RobotImpl.h"
namespace mr
{

	MouseAction::MouseAction(Input::GlobalMouseEvent e) : mEvent(e) {};

	time_t MouseAction::TimeStamp()
	{
		return mEvent.timestamp;
	}

	void MouseAction::DoAction()
	{
		//std::cout << "Doing mouse action" << std::endl;
		switch (mEvent.action)
		{
		case Input::Mouse::MOVE:
			//std::cout << "moving to x=" << mEvent.x << ",y=" << mEvent.y << std::endl;
			RobotImpl::MouseMove(mEvent);
			break;
		case Input::Mouse::PRESS:
			RobotImpl::MousePress(mEvent);
			break;
		case Input::Mouse::RELEASE:
			RobotImpl::MouseRelease(mEvent);
			break;
		}
	}

	KeyboardAction::KeyboardAction(Input::GlobalKeyEvent e) : mEvent(e) {};

	time_t KeyboardAction::TimeStamp()
	{
		return mEvent.timestamp;
	}

	void KeyboardAction::DoAction()
	{
	//	std::cout << "Doing keyboard action" << std::endl;
		switch (mEvent.action)
		{
		case Input::KeyBoard::PRESS:
			RobotImpl::KeyPress(mEvent);
			break;
		case Input::KeyBoard::RELEASE:
			RobotImpl::KeyRelease(mEvent);
			break;
		}
	}
}
