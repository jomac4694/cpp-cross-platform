#include "Playback.h"
#include "RobotFactory.h"
#include "Input.h"
#include "Playback.h"
#include <thread>



	MouseAction::MouseAction(GlobalMouseEvent e) : mEvent(e) {};

	time_t MouseAction::TimeStamp()
	{
		return mEvent.timestamp;
	}

	void MouseAction::DoAction()
	{
		std::cout << "Doing mouse action" << std::endl;
		switch (mEvent.action)
		{
		case Input::Mouse::MOVE:
			std::cout << "moving to x=" << mEvent.x << ",y=" << mEvent.y << std::endl;
			Robot::roby->MoveMouse(mEvent);
			break;
		case Input::Mouse::PRESS:
			Robot::roby->mousePress(mEvent);
			break;
		case Input::Mouse::RELEASE:
			Robot::roby->mouseRelease(mEvent);
			break;
		}
	}

	KeyboardAction::KeyboardAction(GlobalKeyEvent e) : mEvent(e) {};

	time_t KeyboardAction::TimeStamp()
	{
		return mEvent.timestamp;
	}

	void KeyboardAction::DoAction()
	{
		std::cout << "Doing keyboard action" << std::endl;
		switch (mEvent.action)
		{
		case Input::KeyBoard::PRESS:
			Robot::roby->keyPress(mEvent);
			break;
		case Input::KeyBoard::RELEASE:
			Robot::roby->keyRelease(mEvent);
			break;
		}
	}

