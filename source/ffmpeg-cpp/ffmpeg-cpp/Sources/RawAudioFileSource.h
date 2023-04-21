#pragma once

#include "Demuxer.h"
#include "InputSource.h"
#include "ffmpeg.h"


namespace ffmpegcpp
{
class RawAudioFileSource : public InputSource
{
public:
    RawAudioFileSource(const char* fileName, const char* inputFormat, int sampleRate, int channels, FrameSink* frameSink);
    virtual ~RawAudioFileSource();

    virtual void PreparePipeline();
    virtual bool IsDone();
    virtual void Step();

private:
    void CleanUp();

    Demuxer* demuxer = nullptr;
};


} // namespace ffmpegcpp
