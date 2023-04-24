#pragma once

#include "FrameSink.h"
#include "FrameWriter.h"
#include "ffmpeg.h"


namespace ffmpegcpp
{
class OneInputFrameSink : public FrameSink
{
public:
    OneInputFrameSink(FrameWriter* writer, AVMediaType mediaType);
    ~OneInputFrameSink();

    virtual AVMediaType GetMediaType();

    FrameSinkStream* CreateStream();


private:
    int nStreamsGenerated = 0;

    FrameWriter* writer;

    FrameSinkStream* stream = nullptr;

    AVMediaType mediaType;
};
} // namespace ffmpegcpp
