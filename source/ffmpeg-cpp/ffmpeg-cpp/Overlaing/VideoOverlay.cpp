/*
 *      Author: Alexander Ksenofontov
 *      Created on: March Apr 27, 2023
 *      License: MIT
 *      All right reserved
 */

#include "VideoOverlay.h"

namespace ffmpegcpp
{

VideoOverlay::VideoOverlay(FrameSink* frameSink)
: frameSink(frameSink)
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
    /**/
    uint8_t* buff = (uint8_t*)frame->data[0];
    if (buff) {
        for (size_t y = 0; y < 100; y++) {
            for (size_t x = 0; x < 100; x++) {
                buff[y * frame->width + x] = 0xff;
            }
        }
    }

    sinkStream->WriteFrame(frame, metaData);
}

} // namespace ffmpegcpp
