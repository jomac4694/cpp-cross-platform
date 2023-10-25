#pragma once
#include <iostream>
#include "EventSubscriber.h"
#include <list>
#include <mutex>
#include "Playback.h"
class EventPublisher
{
public:
    EventPublisher(EventPublisher const&) = delete;
    EventPublisher& operator=(EventPublisher const&) = delete;

    static std::shared_ptr<EventPublisher> Instance()
    {
        static std::shared_ptr<EventPublisher> s{new EventPublisher};
        return s;
    }
    void Subscribe(std::shared_ptr<EventSubscriber> subby) { mSubbies.push_back(subby);};
    void Unsubscribe(std::shared_ptr<EventSubscriber> subby) { mSubbies.remove(subby);};
    void Notify(mr::Input::GlobalMouseEvent e)
    { 
        for (auto &sub : mSubbies)
        {
            std::lock_guard<std::mutex> lk(mut);
            sub->OnMouseMove(e);
        }
    }

private:
    EventPublisher() {}
    std::list<std::shared_ptr<EventSubscriber>> mSubbies;
    std::mutex mut;

};

class TestSub : public EventSubscriber
{
    public:
        void OnMouseMove(mr::Input::GlobalMouseEvent m) override {
            std::cout << "the mouse is movinggggggggggggggg" << std::endl;
            mr::MouseAction e(m);
           // mMut.lock();
            mActions.push_back(std::make_shared<mr::MouseAction>(e));
           // mMut.unlock();
        }
        std::vector<std::shared_ptr<mr::PlaybackAction>> GetActions();
        int GetNumActions();
    private:
        std::vector<std::shared_ptr<mr::PlaybackAction>> mActions;
        std::mutex mMut;
};

class TestSub2 : public EventSubscriber
{
    public:
        void OnMouseMove(mr::Input::GlobalMouseEvent m) override {
            std::cout << "the mouse is in another subby" << std::endl;
            mr::MouseAction e(m);
           // mMut.lock();
            mActions.push_back(std::make_shared<mr::MouseAction>(e));
           // mMut.unlock();
        }
        std::vector<std::shared_ptr<mr::PlaybackAction>> GetActions();
        int GetNumActions();
    private:
        std::vector<std::shared_ptr<mr::PlaybackAction>> mActions;
        std::mutex mMut;
};