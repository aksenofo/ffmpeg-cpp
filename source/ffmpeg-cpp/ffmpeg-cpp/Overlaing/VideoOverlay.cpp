/*
 *      Author: Alexander Ksenofontov
 *      Created on: March Apr 27, 2023
 *      License: MIT
 *      All right reserved
 */

#include "VideoOverlay.h"

namespace ffmpegcpp
{

VideoOverlay::VideoOverlay(FrameSink* frameSink, VideoOverlayAdapter* videoOverlayAdapter)
: frameSink(frameSink)
, videoOverlayAdapter(videoOverlayAdapter)
{
    sinkStream = frameSink->CreateStream();
}

FrameSinkStream* VideoOverlay::CreateStream()

{
    stream = new FrameSinkStream(this, 0);
    return stream;
}

bool VideoOverlay::IsPrimed()
{
    return true;
}

void VideoOverlay::Close(int streamIndex)
{
    sinkStream->Close();
    delete stream;
}

void VideoOverlay::WriteFrame(int streamIndex, AVFrame* frame, StreamData* metaData)
{

    AVFrame* newFrame = videoOverlayAdapter->DoOverlay(frame);

    sinkStream->WriteFrame(newFrame, metaData);
    av_frame_unref(newFrame);
}

} // namespace ffmpegcpp
