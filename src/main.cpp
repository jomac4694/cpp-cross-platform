#include <iostream>
#include <thread>
#include <chrono>
#include "/Users/josephmcilvaine/cpp-cross-platform/include/RobotImpl.h"
#ifdef _WIN32
#include <Windows.h>

void test_drawing()
{

    /* hide console window */
    ShowWindow(GetConsoleWindow(), SW_HIDE);

    /* Calling GetDC with argument 0 retrieves the desktop's DC */
    HDC hDC_Desktop = GetDC(0);

    /* Draw a simple blue rectangle on the desktop */
    RECT rect = {20, 20, 200, 200};
    LOGBRUSH lb;
    lb.lbStyle = BS_SOLID;
    lb.lbColor = RGB(0, 255, 0);
    lb.lbHatch = 0;
    HGDIOBJ pen = CreatePen(PS_COSMETIC, 5, RGB(0, 255, 0));
    HGDIOBJ old;
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
    DeleteObject(pen); // you must delete GDI object!
    Sleep(5000);
}
#endif
/*
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


struct MyPoint {
   int x, y; 
   MyPoint() :x(0), y(0) { }
   MyPoint(int xx, int yy) :x(xx), y(yy) { }
};

CGEventRef OnMouseEvent(CGEventTapProxy proxy, CGEventType type, CGEventRef event, void *userInfo)
{
    std::cout << "in here now" << std::endl;
    if (type == kCGEventLeftMouseUp)
    {
        std::cout << "left mouse is up" << std::endl;
    }
    else if (type == kCGEventKeyUp)
    {
        std::cout << "key is up mofo" << std::endl;
    }
    else if (type == kCGEventKeyDown)
    {
        std::cout << "key is down" << std::endl;
    }
    else if (type == kCGEventMouseMoved)
    {
        std::cout << "mouse moving" << std::endl;
    }
    return event;
}

void do_listening()
{
        std::cout << "starting macro recorder" << std::endl;
    bool Result = false;
    const void * Keys[] = { kAXTrustedCheckOptionPrompt };
    const void * Values[] = { kCFBooleanTrue };

    CFDictionaryRef Options;
    Options = CFDictionaryCreate(kCFAllocatorDefault,
                                 Keys, Values, sizeof(Keys) / sizeof(*Keys),
                                 &kCFCopyStringDictionaryKeyCallBacks,
                                 &kCFTypeDictionaryValueCallBacks);

    AXIsProcessTrustedWithOptions(Options);
    CFRunLoopRef ref = CFRunLoopGetCurrent();
    
    CGEventMask mask = CGEventMaskBit(kCGEventLeftMouseDown) |
                       CGEventMaskBit(kCGEventLeftMouseUp) |
                       CGEventMaskBit(kCGEventRightMouseDown) |
                       CGEventMaskBit(kCGEventRightMouseUp) |
                       CGEventMaskBit(kCGEventMouseMoved) |
                       CGEventMaskBit(kCGEventLeftMouseDragged) |
                       CGEventMaskBit(kCGEventRightMouseDragged) |
                       CGEventMaskBit(kCGEventScrollWheel);

    CFMachPortRef tap =
        CGEventTapCreate(kCGHIDEventTap, kCGHeadInsertEventTap,
                         kCGEventTapOptionDefault, kCGEventMaskForAllEvents, OnMouseEvent, NULL);

    
    CFRunLoopSourceRef source =
        CFMachPortCreateRunLoopSource(kCFAllocatorDefault, tap, 0);
    CFRunLoopAddSource(ref, source, kCFRunLoopCommonModes);
    if (!CGEventTapIsEnabled(tap))
        std::cout << "yerrrrrr" << std::endl;
    CGEventTapEnable(tap, true);

    CFRunLoopRun();

    
    std::cout << "doing shizz" << std::endl;
}

   void mouse_event(CGMouseButton button, CGEventType type, CGPoint location)
   {
      CGEventRef event = CGEventCreateMouseEvent(NULL, type, location, button);
      CGEventSetType(event, type);
      CGEventPost(kCGHIDEventTap, event);
      CFRelease(event);
   }

   void set_mouse_loc(MyPoint p) 
{
   CGPoint location = CGPointMake(p.x, p.y);
   mouse_event(kCGMouseButtonLeft, kCGEventMouseMoved, location);
}

void domouse()
{
        for (int i = 0; i < 750; i++)
    {
        MyPoint p;
        p.x = i;
        p.y = i;
        set_mouse_loc(p);
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
}

void DoJob()
{
    Input::KeyBoard::Action a;
    MacGlobalListener listen;
    listen.Start();
}
*/
int main()
{
    mr::RobotImpl::KeyPress(GlobalKeyEvent());
    for (int i = 0; i < 250; i++)
    {
        GlobalMouseEvent e;
        e.x = i;
        e.y = i;
        e.action = Mouse::Action::MOVE;
        mr::RobotImpl::MouseMove(e);
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
    return 0;
}


