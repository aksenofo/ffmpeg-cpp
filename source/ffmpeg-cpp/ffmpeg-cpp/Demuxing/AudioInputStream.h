#pragma once

#include "Frame_Sinks/AudioFrameSink.h"
#include "InputStream.h"
#include "ffmpeg.h"

namespace ffmpegcpp
{
class AudioInputStream : public InputStream
{

public:
    AudioInputStream(AVFormatContext* format, AVStream* stream);
    ~AudioInputStream();

    void AddStreamInfo(ContainerInfo* info);

    AVMediaType GetMediaType() const {
        return AVMEDIA_TYPE_AUDIO;
    }

protected:
    virtual void ConfigureCodecContext();
};
} // namespace ffmpegcpp
