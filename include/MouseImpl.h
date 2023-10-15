#pragma once
#include "Utils.h"


class MouseImpl
{
public:
	void OnMouseMove(MouseMove e)
	{
		std::cout << "x=" << e.p.x << std::endl;
		std::cout << "y=" << e.p.y << std::endl;

	}
	virtual void OnMouseClick(MouseEvent e);

};