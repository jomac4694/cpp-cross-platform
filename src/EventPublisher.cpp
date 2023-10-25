#pragma once
#include "EventPublisher.h"


std::vector<std::shared_ptr<mr::PlaybackAction>> TestSub::GetActions()
{
    return mActions;
}

int TestSub::GetNumActions()
{
   // mMut.lock();
    size_t size = mActions.size();
   // mMut.unlock();
    return size;
}

std::vector<std::shared_ptr<mr::PlaybackAction>> TestSub2::GetActions()
{
    return mActions;
}

int TestSub2::GetNumActions()
{
   // mMut.lock();
    size_t size = mActions.size();
   // mMut.unlock();
    return size;
}