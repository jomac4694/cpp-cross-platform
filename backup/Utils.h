#pragma once
namespace
{

	enum ClickType
	{
		LBUTTON_DOWN, LBUTTON_UP, RBUTTON_DOWN, RBUTTON_UP
	};
	struct Point
	{
		int x;
		int y;
	};

	struct MouseEvent
	{

	};

	struct MouseMove : MouseEvent
	{
		Point p;
	};

	struct MouseClick : MouseEvent
	{
		ClickType type;
	};
}