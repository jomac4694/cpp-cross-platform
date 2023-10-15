#include "GlobalListener.h"
#include "Playback.h"
#include <thread>
#include <mutex>
#include "RobotFactory.h"



extern std::shared_ptr<Recording> mRecording;
extern std::shared_ptr<RecordingState> mState;
ActiveRecordingManager::ActiveRecordingManager() {
}

DWORD WINAPI ActiveRecordingManager::Replay(PVOID lpParam)
{
	/*
	std::cout << "thread starting" << std::endl;
	for (int i = 1; i < mRecording->size(); i++)
	{
		auto currAction = mRecording[i - 1];
		auto nextAction = mRecording[i];
		currAction->DoAction();
		auto delta_t = nextAction->TimeStamp() - currAction->TimeStamp();
		std::cout << "currTs=" << currAction->TimeStamp() << std::endl;
		std::cout << "nextTs=" << nextAction->TimeStamp() << std::endl;
		std::cout << "delta_t=" << delta_t << std::endl;
		std::this_thread::sleep_for(std::chrono::microseconds(1));
	}
	*/
	return 0;
}

RecordingState state()
{
	std::mutex m;
	m.lock();
	RecordingState s = *mState;
	m.unlock();
	return s;
}

void ActiveRecordingManager::OnKeyPress(GlobalKeyEvent e)
{
	std::cout << "key=" << e.key << std::endl;
	std::cout << "state=" << state() << std::endl;
	//std::cout << "size=" << mRecording->size() << std::endl;
	if (e.key == Input::KeyBoard::Num1 && state() != ACTIVE)
	{
		std::cout << "recording is active" << std::endl;
		std::mutex m;
		m.lock();
		*mState = ACTIVE;
		m.unlock();
		return;
	}
	else if (e.key == Input::KeyBoard::F3 && state() == ACTIVE)
	{
		std::cout << "recording is stopped" << std::endl;
		std::mutex m;
		m.lock();
		*mState = STOPPED;
		m.unlock();
		return;
	}
	/*
	else if (e.key == Input::KeyBoard::F4)
	{
		std::cout << "Playing back" << std::endl;
		//std::thread t1(&ActiveRecordingManager::Replay, this);
		//t1.join();
		HANDLE win_thread;
		win_thread = CreateThread(NULL, 0, ActiveRecordingManager::Replay, NULL, 0, NULL);
		if (win_thread == NULL)
		{
			return;
		}
		SetThreadPriority(win_thread, THREAD_PRIORITY_HIGHEST);
		WaitForSingleObject(win_thread, INFINITE);

	}
	*/
	else if (state() == ACTIVE)
	{
		std::mutex m;
		m.lock();
		mRecording->push_back(std::shared_ptr<PlaybackAction>{new KeyboardAction(e)});
		m.unlock();
	}
}
void ActiveRecordingManager::OnKeyRelease(GlobalKeyEvent e) 
{
	if (state() == ACTIVE)
	{
		std::mutex m;
		m.lock();
		mRecording->push_back(std::shared_ptr<PlaybackAction>{new KeyboardAction(e)});
		m.unlock();
	}
}
void ActiveRecordingManager::OnMouseMove(GlobalMouseEvent e)
{
	if (state() == ACTIVE)
	{
		std::cout << "pushing" << e.button << std::endl;
		std::mutex m;
		m.lock();
		mRecording->push_back(std::shared_ptr<PlaybackAction>{new MouseAction(e)});
		m.unlock();
	}
}
void ActiveRecordingManager::OnMousePress(GlobalMouseEvent e)
{
	std::cout << "button=" << e.button << std::endl;
	if (state() == ACTIVE)
	{
		std::mutex m;
		m.lock();
		mRecording->push_back(std::shared_ptr<PlaybackAction>{new MouseAction(e)});
		m.unlock();
	}
}
void ActiveRecordingManager::OnMouseRelease(GlobalMouseEvent e)
{
	std::cout << "button=" << e.button << std::endl;
	if (state() == ACTIVE)
	{
		std::mutex m;
		m.lock();
		mRecording->push_back(std::shared_ptr<PlaybackAction>{new MouseAction(e)});
		m.unlock();
	}
}