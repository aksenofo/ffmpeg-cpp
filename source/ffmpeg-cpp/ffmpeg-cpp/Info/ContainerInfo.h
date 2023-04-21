#pragma once

#include "AudioStreamInfo.h"
#include "VideoStreamInfo.h"
#include "ffmpeg.h"
#include "std.h"

namespace ffmpegcpp
{
struct ContainerInfo {
    long durationInMicroSeconds;
    float durationInSeconds;
    float start;
    float bitRate;
    const AVInputFormat* format;

    std::vector<VideoStreamInfo> videoStreams;
    std::vector<AudioStreamInfo> audioStreams;
};


} // namespace ffmpegcpp
