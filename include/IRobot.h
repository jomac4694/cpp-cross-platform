#pragma once
#include "GlobalListener.h"
class IRobot
{
public:
	virtual void KeyPress(GlobalKeyEvent e) = 0;
	virtual void KeyRelease(GlobalKeyEvent e) = 0;
	virtual void MoveMove(GlobalMouseEvent e) = 0;
	virtual void MousePress(GlobalMouseEvent e) = 0;
	virtual void MouseRelease(GlobalMouseEvent e) = 0;
};


class RobotSingleton
{
public:
	RobotSingleton(std::shared_ptr<IRobot>);

	std::shared_ptr<IRobot> mRobot;
	static std::shared_ptr<RobotSingleton> GetInstance(std::shared_ptr<IRobot> roby);
	void keyPress(GlobalKeyEvent e);
	void keyRelease(GlobalKeyEvent e);
	void MoveMouse(GlobalMouseEvent e);
	void mousePress(GlobalMouseEvent e);
	void mouseRelease(GlobalMouseEvent e);
};