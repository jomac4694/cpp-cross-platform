#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include "RobotImpl.h"
#include "RobotFactory.h"
#include "MacGlobalListener.h"
#include "EventPublisher.h"
std::shared_ptr<Recording> mRecording;
#ifdef _WIN32
#include <Windows.h>
#include "WindowsGlobalListener.h"

//std::shared_ptr<Recording> mRecording;
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
        time_t start = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    time_t curr = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
   // std::thread t1(job);

    
    mRecording = std::shared_ptr<std::vector<std::shared_ptr<mr::PlaybackAction>>>(new Recording);

    WindowsGlobalListener listener;
    listener.Start();
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        curr = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        std::cout << "curr-start=" << (curr - start) << std::endl;
        if ((curr - start) >= 1000)
            break;
    }

    listener.Stop();
    
    mr::RobotImpl::KeyPress(GlobalKeyEvent());
    for (int i = 0; i < 250; i++)
    {
        GlobalMouseEvent e;
        e.x = 50;
        e.y = 50;
        e.action = Mouse::Action::MOVE;
        mr::RobotImpl::MouseMove(e);
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }

 //   t1.join();
    std::cout << "record_size=" << mRecording->size() << std::endl;
    for (int i = 1; i < mRecording->size(); i++)
    {
                auto currAction = mRecording->at(i - 1);
                auto nextAction = mRecording->at(i);
                currAction->DoAction();
                auto delta_t = nextAction->TimeStamp() - currAction->TimeStamp();
              //  std::cout << "currTs=" << currAction->TimeStamp() << std::endl;
              //  std::cout << "nextTs=" << nextAction->TimeStamp() << std::endl;
              //  std::cout << "delta_t=" << delta_t << std::endl;
               time_t t1 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
               time_t t2 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
               while ((t2 - t1) <= delta_t)
                    t2 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    }
    std::cout << "exting?" << std::endl;
}
void ajob()
{
   MacGlobalListener listener;
   listener.Start();
}

        
    for (int i = 1; i < s->GetActions().size(); i++)
    {
                auto currAction = s->GetActions().at(i - 1);
                auto nextAction = s->GetActions().at(i);
                currAction->DoAction();
                auto delta_t = nextAction->TimeStamp() - currAction->TimeStamp();
              //  std::cout << "currTs=" << currAction->TimeStamp() << std::endl;
              //  std::cout << "nextTs=" << nextAction->TimeStamp() << std::endl;
               std::cout << "delta_t=" << delta_t << std::endl;
               time_t t1 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
               time_t t2 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
               while ((t2 - t1) <= delta_t)
                    t2 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    }
*/

void DoJob()
{
    MacGlobalListener listen;
    listen.Start();

}

int main()
{
    std::thread t1(DoJob);
    std::shared_ptr<TestSub> s = std::shared_ptr<TestSub>(new TestSub);
    EventPublisher::Instance()->Subscribe(s);

    std::shared_ptr<TestSub2> s2 = std::shared_ptr<TestSub2>(new TestSub2);
    EventPublisher::Instance()->Subscribe(s2);
    t1.join();
    /*
    for (int i = 0; i < 5; i++)
    {
        mr::Input::GlobalKeyEvent k;
        k.key = mr::Input::KeyBoard::A;
        mr::RobotImpl::KeyPress(k);
        mr::RobotImpl::KeyRelease(k);
        sleep(10);
    }
    
    std::thread t1(DoJob);
    std::shared_ptr<TestSub> s = std::shared_ptr<TestSub>(new TestSub);
    EventPublisher::Instance()->Subscribe(s);
    while (true)
    {
        //std::cout << "WERE GOING IN" << std::endl;
    std::mutex m;
    if (s->GetNumActions() > 1000)
    {
        std::cout << "we hit 1000" << std::endl;
            for (int i = 1; i < s->GetActions().size(); i++)
    {
                auto currAction = s->GetActions().at(i - 1);
                auto nextAction = s->GetActions().at(i);
                currAction->DoAction();
                auto delta_t = nextAction->TimeStamp() - currAction->TimeStamp();
              //  std::cout << "currTs=" << currAction->TimeStamp() << std::endl;
              //  std::cout << "nextTs=" << nextAction->TimeStamp() << std::endl;
               std::cout << "delta_t=" << delta_t << std::endl;
               time_t t1 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
               time_t t2 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
               while ((t2 - t1) <= delta_t)
                    t2 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    }
    std::cout << "bye" << std::endl;
    exit(0);
    }



    }
  //  m.unlock();
    
    std::thread t1(ajob);
    mRecording = std::shared_ptr<std::vector<std::shared_ptr<mr::PlaybackAction>>>(new Recording);
 
    while (true){
      //  std::cout << "eyooo" << std::endl;

        std::mutex m;
        m.lock();
        size_t recording_size = mRecording->size();
        m.unlock();
        std::cout << "size=" << recording_size << std::endl;
        if (recording_size >= 500)
        {
            std::cout << "size exceeded" << std::endl;
            break;
        }
    }
    std::mutex m;
    m.lock();
    for (int i = 1; i < mRecording->size(); i++)
    {
                auto currAction = mRecording->at(i - 1);
                auto nextAction = mRecording->at(i);
                currAction->DoAction();
                auto delta_t = nextAction->TimeStamp() - currAction->TimeStamp();
              //  std::cout << "currTs=" << currAction->TimeStamp() << std::endl;
              //  std::cout << "nextTs=" << nextAction->TimeStamp() << std::endl;
               std::cout << "delta_t=" << delta_t << std::endl;
               time_t t1 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
               time_t t2 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
               while ((t2 - t1) <= delta_t)
                    t2 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    }
    m.unlock();
    t1.join();
    CGContextRef drawContext = 0;

    CGRect rect;
    CGSize s;
    s.width = 100;
    s.height = 100;
    rect.size = s;
    rect.origin.x = 0;
    rect.origin.y = -rect.size.height;
    static const CGFloat white [] = {1.0, 1.0, 1.0, 1.0};
    CGContextScaleCTM(drawContext, 1, -1);
    CGContextSetFillColor(drawContext, white);
    CGContextFillRect(drawContext, rect);
    while (true){};
    CGContextRelease(drawContext);
    */
    return 0;
}


