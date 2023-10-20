#include "/Users/josephmcilvaine/cpp-cross-platform/include/RobotImpl.h"
#include "ApplicationServices/ApplicationServices.h"
#include <iostream>
namespace
{
   void PostMouseEvent(CGMouseButton button, CGEventType type, CGPoint location)
   {
      CGEventRef event = CGEventCreateMouseEvent(NULL, type, location, button);
      CGEventSetType(event, type);
      CGEventPost(kCGHIDEventTap, event);
      CFRelease(event);
   }
}

namespace mr::RobotImpl
{
    void KeyPress(GlobalKeyEvent e)
    {
        std::cout << "Mac Key press" << std::endl;
    }

	void KeyRelease(GlobalKeyEvent e)
    {
        std::cout << "Mac key release" << std::endl;
    }

	void MouseMove(GlobalMouseEvent e)
    {
       CGPoint location = CGPointMake(e.x, e.y);
       PostMouseEvent(kCGMouseButtonLeft, kCGEventMouseMoved, location);
    }

	void MousePress(GlobalMouseEvent e)
    {
        CGEventType type = e.button == mr::Input::Mouse::Button::Left ? kCGEventLeftMouseDown : kCGEventRightMouseDown;
        CGMouseButton button = e.button == mr::Input::Mouse::Button::Left ? kCGMouseButtonLeft : kCGMouseButtonRight;
        CGPoint location;
        location.x = e.x;
        location.y = e.y;
        PostMouseEvent(button,  type,  location);
        
    }

	void MouseRelease(GlobalMouseEvent e)
    {
        CGEventType type = e.button == mr::Input::Mouse::Button::Left ? kCGEventLeftMouseUp : kCGEventRightMouseUp;
        CGMouseButton button = e.button == mr::Input::Mouse::Button::Left ? kCGMouseButtonLeft : kCGMouseButtonRight;
        CGPoint location;
        location.x = e.x;
        location.y = e.y;
        PostMouseEvent(button,  type,  location);
    }
}