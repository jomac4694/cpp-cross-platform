#pragma once
#include "Playback.h"
#include <iostream>

    typedef std::vector<std::shared_ptr<mr::PlaybackAction>> Recording;
    extern std::shared_ptr<Recording> mRecording;
