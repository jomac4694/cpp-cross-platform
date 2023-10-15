#include <iostream>
#include <Windows.h>
#include <windowsx.h>
#include "WindowsGlobalListener.h"
#include "WindowsRobotImpl.h"
#include <thread>
#include "Playback.h"
#include "RobotFactory.h"
#include <mutex>
#include <random>



using namespace Robot;

 std::shared_ptr<Recording> mRecording = std::shared_ptr< Recording>(new Recording);
 std::shared_ptr<RecordingState> mState = std::shared_ptr<RecordingState>(new RecordingState);
void test_drawing()
{

    /* hide console window */
    ShowWindow(GetConsoleWindow(), SW_HIDE);

    /* Calling GetDC with argument 0 retrieves the desktop's DC */
    HDC hDC_Desktop = GetDC(0);

    /* Draw a simple blue rectangle on the desktop */
    RECT rect = { 20, 20, 200, 200 };
    LOGBRUSH lb;
    lb.lbStyle = BS_SOLID;
    lb.lbColor = RGB(0, 255, 0);
    lb.lbHatch = 0;
    HGDIOBJ  pen = CreatePen(PS_COSMETIC, 5, RGB(0, 255, 0));
    HGDIOBJ  old;
    while (true)
    {
        for (int i = 100; i < 500; i++)
        {
            SetPixel(hDC_Desktop, i, i, RGB(0, 255, 0));
            old = SelectObject(hDC_Desktop, pen);
            MoveToEx(hDC_Desktop, 0, 0, NULL);
            LineTo(hDC_Desktop, 1000, 1000);
            // ReleaseDC(NULL, hDC_Desktop);
            SelectObject(hDC_Desktop, old);
            Sleep(1);
        }

        Sleep(1);
    }
    DeleteObject(pen); //you must delete GDI object!
    Sleep(5000);

}

void job()
{
    WindowsGlobalListener listener;
    listener.Start();
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        Sleep(20);

    }


    listener.Stop();
}

void job2()
{
    while (true) {

        std::mutex m;
        m.lock();
        int vec_size = mRecording->size();
        bool active = *mState != ACTIVE;
        m.unlock();
        //std::cout << "size_main=" << vec_size << std::endl;
        //std::cout << "state_main=" << active << std::endl;

        if (active != ACTIVE && vec_size > 1)
        {
            for (int i = 1; i < mRecording->size(); i++)
            {
                auto currAction = mRecording->at(i - 1);
                auto nextAction = mRecording->at(i);
                currAction->DoAction();
                auto delta_t = nextAction->TimeStamp() - currAction->TimeStamp();
                std::cout << "currTs=" << currAction->TimeStamp() << std::endl;
                std::cout << "nextTs=" << nextAction->TimeStamp() << std::endl;
                std::cout << "delta_t=" << delta_t << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2));
            }
            mRecording->clear();
        }
        else
        {
            Sleep(1000);
        }


    }
}
void main()
{
    /*
    std::thread t1(job);
    std::thread t2(job2);
    while(true) {
            Sleep(1000);
    }



    t1.join();
    t2.join();

    */
    for (int i = 0; i < 500; i++)
    {
        GlobalMouseEvent e;
        e.action = Input::Mouse::MOVE;
        e.x = 100;
        e.y = i;
        e.timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        std::mutex m;
        m.lock();
        mRecording->push_back(std::shared_ptr<PlaybackAction>{new MouseAction(e)});
        m.unlock();
    }

    for (int i = 100; i < 400; i++)
    {
        GlobalMouseEvent e;
        e.action = Input::Mouse::MOVE;
        e.x = i;
        e.y = 500;
        e.timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        std::mutex m;
        m.lock();
        mRecording->push_back(std::shared_ptr<PlaybackAction>{new MouseAction(e)});
        m.unlock();
    }

    for (int i = 1; i < mRecording->size(); i++)
    {
        auto currAction = mRecording->at(i - 1);
        auto nextAction = mRecording->at(i);
        currAction->DoAction();
        auto delta_t = (std::rand() % 10) + 0;
        std::cout << "currTs=" << currAction->TimeStamp() << std::endl;
        std::cout << "nextTs=" << nextAction->TimeStamp() << std::endl;
        std::cout << "delta_t=" << delta_t << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    

}


