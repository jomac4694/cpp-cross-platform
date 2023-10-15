#pragma once
#include "IRobot.h"
class WindowsRobotImpl : public IRobot
{
public:
	WindowsRobotImpl();
	virtual void KeyPress(GlobalKeyEvent e) override;
	virtual void KeyRelease(GlobalKeyEvent e) override;
	virtual void MoveMove(GlobalMouseEvent e) override;
	virtual void MousePress(GlobalMouseEvent e) override;
	virtual void MouseRelease(GlobalMouseEvent e) override;
};