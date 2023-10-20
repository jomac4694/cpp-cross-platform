#include "IRobot.h"


RobotSingleton::RobotSingleton(std::shared_ptr<IRobot> roby) : mRobot(roby)
{
	
}

std::shared_ptr<RobotSingleton> RobotSingleton::GetInstance(std::shared_ptr<IRobot> roby)
{
	std::shared_ptr<RobotSingleton> mSingleton = std::shared_ptr<RobotSingleton>{new RobotSingleton(roby)};
	return mSingleton;
}

void RobotSingleton::keyPress(GlobalKeyEvent e)
{
	mRobot->KeyPress(e);
};
void RobotSingleton::keyRelease(GlobalKeyEvent e)
{
	mRobot->KeyRelease(e);
};
void RobotSingleton::MoveMouse(GlobalMouseEvent e)
{
	mRobot->MoveMove(e);
};
void RobotSingleton::mousePress(GlobalMouseEvent e)
{
	mRobot->MousePress(e);
};
void RobotSingleton::mouseRelease(GlobalMouseEvent e)
{
	mRobot->MouseRelease(e);
};