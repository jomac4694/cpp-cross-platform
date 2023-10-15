#pragma once
#include "IRobot.h"
#include "WindowsRobotImpl.h"
#include "GlobalListener.h"
namespace Robot
{
    static std::shared_ptr<IRobot> wind = std::shared_ptr<IRobot>(new WindowsRobotImpl);
	static std::shared_ptr<RobotSingleton> roby = RobotSingleton::GetInstance(wind);
	static std::shared_ptr<IListeningContext> context = std::shared_ptr<IListeningContext>(new ActiveRecordingManager);


}
typedef std::vector<std::shared_ptr<PlaybackAction>> Recording;
extern std::shared_ptr<Recording> mRecording;
extern std::shared_ptr<RecordingState> mState;