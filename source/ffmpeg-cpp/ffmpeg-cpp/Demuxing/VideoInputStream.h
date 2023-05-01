#pragma once

#include "Frame_Sinks/VideoFrameSink.h"
#include "Info/VideoStreamInfo.h"
#include "InputStream.h"
#include "ffmpeg.h"

namespace ffmpegcpp
{
class VideoInputStream : public InputStream
{

public:
    VideoInputStream(AVFormatContext* format, AVStream* stream);
    ~VideoInputStream();

    void AddStreamInfo(ContainerInfo* info);

    AVMediaType GetMediaType() const {
        return AVMEDIA_TYPE_VIDEO;
    }

protected:
    virtual void ConfigureCodecContext();
};
} // namespace ffmpegcpp
