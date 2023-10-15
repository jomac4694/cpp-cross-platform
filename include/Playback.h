#pragma once
#include <vector>
#include "GlobalListener.h"
class PlaybackAction
{
public:
	virtual void DoAction() = 0;
	virtual time_t TimeStamp() = 0;
};

class KeyboardAction : public PlaybackAction
{
public:
	KeyboardAction(GlobalKeyEvent e);
	void DoAction() override;
	time_t TimeStamp() override;


private:
	GlobalKeyEvent mEvent;

};
class MouseAction : public PlaybackAction
{
public:
	MouseAction(GlobalMouseEvent e);
	void DoAction() override;
	time_t TimeStamp() override;

private:
	GlobalMouseEvent mEvent;

};
