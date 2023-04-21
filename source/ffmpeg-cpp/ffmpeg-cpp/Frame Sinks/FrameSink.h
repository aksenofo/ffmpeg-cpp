#pragma once

#include "FrameSinkStream.h"
#include "ffmpeg.h"

namespace ffmpegcpp
{
class FrameSink
{
public:
    virtual FrameSinkStream* CreateStream() = 0;

    virtual AVMediaType GetMediaType() = 0;

    virtual ~FrameSink() {}
};


} // namespace ffmpegcpp
