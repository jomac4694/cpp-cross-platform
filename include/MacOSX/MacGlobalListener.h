#include "GlobalListener.h"
#include "ApplicationServices/ApplicationServices.h"


class MacGlobalListener : public IGlobalListener
{
    public:
        MacGlobalListener();
        void Start() override;
        void Stop() override;
       // void SetContext(std::shared_ptr<IListeningContext> context) override;

    private:
        static CGEventRef OnInput(CGEventTapProxy proxy, CGEventType type, CGEventRef event, void *userInfo);
        //std::shared_ptr<IListeningContext> mContext;
};