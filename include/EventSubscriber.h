#pragma once
#include "Input.h"
class EventSubscriber
{

    public:
        virtual void OnMouseMove(mr::Input::GlobalMouseEvent e) = 0;
};

