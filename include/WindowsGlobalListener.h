#pragma once
#include "GlobalListener.h"
#include <Windows.h>
#include <windowsx.h>
class WindowsGlobalListener : public IGlobalListener
{

public:
	WindowsGlobalListener();
	void Start() override;
	void Stop() override;
	static LRESULT __stdcall KeyboardCallback(int nCode, WPARAM wParam, LPARAM lParam);
	static LRESULT __stdcall MouseCallback(int nCode, WPARAM wParam, LPARAM lParam);
	void SetHook();

};