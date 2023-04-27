/*
 *      Author: Alexander Ksenofontov
 *      Created on: March Apr 27, 2023
 *      License: MIT
 *      All right reserved
 */

#pragma once

#include <Frame_Sinks/VideoFrameSink.h>

namespace ffmpegcpp
{

class VideoOverlay final : public VideoFrameSink, public FrameWriter
{
public:
    VideoOverlay(FrameSink* frameSink);

    FrameSinkStream* CreateStream() override;

    bool IsPrimed() override;

    void Close(int streamIndex) override;

    void WriteFrame(int streamIndex, AVFrame* frame, StreamData* metaData) override;

private:
    FrameSinkStream* stream;
    FrameSink* frameSink;
    FrameSinkStream* sinkStream;
};

} // namespace ffmpegcpp

