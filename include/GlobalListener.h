#pragma once
#include "Input.h"
#include <iostream>
#include <vector>
//#include "Windows.h"





using namespace mr::Input;
enum RecordingState { ACTIVE, STOPPED, PAUSED };


class IListeningContext
{
public:
	virtual void OnKeyPress(GlobalKeyEvent e) = 0;
	virtual void OnKeyRelease(GlobalKeyEvent e) = 0;
	virtual void OnMouseMove(GlobalMouseEvent e) = 0;
	virtual void OnMousePress(GlobalMouseEvent e) = 0;
	virtual void OnMouseRelease(GlobalMouseEvent e) = 0;

};
class IGlobalListener
{
public:;
	  virtual void Start() = 0;
	  virtual void Stop() = 0;
	 // virtual void SetContext(std::shared_ptr<IListeningContext> context) = 0;
};


class ActiveRecordingManager : public IListeningContext
{
public:
	ActiveRecordingManager();
	void OnKeyPress(GlobalKeyEvent e) override;
	void OnKeyRelease(GlobalKeyEvent e) override;
	void OnMouseMove(GlobalMouseEvent e) override;
	void OnMousePress(GlobalMouseEvent e) override;
	void OnMouseRelease(GlobalMouseEvent e) override;
	//static DWORD WINAPI Replay(LPVOID lpParam);


private:
	

};

namespace Context
{
	class ContextManager
	{
	public:
		static std::shared_ptr<IListeningContext> mContext;
		static void SetContext(std::shared_ptr<IListeningContext> context)
		{
			mContext = context;
		}
		static std::shared_ptr<IListeningContext> GetContext()
		{
			return mContext;
		}
	};
}


