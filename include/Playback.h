#pragma once
#include <vector>
#include "Input.h"
namespace mr
{
class PlaybackAction
{
public:
	virtual void DoAction() = 0;
	virtual time_t TimeStamp() = 0;
};

class KeyboardAction : public PlaybackAction
{
public:
	KeyboardAction(Input::GlobalKeyEvent e);
	void DoAction() override;
	time_t TimeStamp() override;


private:
	Input::GlobalKeyEvent mEvent;

};
class MouseAction : public PlaybackAction
{
public:
	MouseAction(Input::GlobalMouseEvent e);
	void DoAction() override;
	time_t TimeStamp() override;

private:
	Input::GlobalMouseEvent mEvent;

};
}
