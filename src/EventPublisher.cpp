#pragma once
#include "EventPublisher.h"


std::vector<std::shared_ptr<mr::PlaybackAction>> TestSub::GetActions()
{
    return mActions;
}

int TestSub::GetNumActions()
{
    mMut.lock();
    size_t size = mActions.size();
    mMut.unlock();
    return size;
}