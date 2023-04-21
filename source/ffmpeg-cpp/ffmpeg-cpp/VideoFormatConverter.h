#pragma once

#include "ConvertedAudioProcessor.h"
#include "ffmpeg.h"

namespace ffmpegcpp
{
class VideoFormatConverter
{
public:
    VideoFormatConverter(AVCodecContext* codecContext);
    ~VideoFormatConverter();

    AVFrame* ConvertFrame(AVFrame* frame);



private:
    void CleanUp();

    void InitDelayed(AVFrame* frame);


    AVCodecContext* codecContext;

    bool initialized = false;

    AVFrame* converted_frame = nullptr;
    struct SwsContext* swsContext = nullptr;
};


} // namespace ffmpegcpp
