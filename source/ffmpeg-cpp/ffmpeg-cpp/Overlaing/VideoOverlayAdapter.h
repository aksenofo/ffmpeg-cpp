/*
 *      Author: Alexander Ksenofontov
 *      Created on: March Apr 27, 2023
 *      License: MIT
 *      All right reserved
 */

#pragma once

struct AVFrame;

namespace ffmpegcpp
{

class VideoOverlayAdapter
{
public:
    VideoOverlayAdapter() = default;
    virtual ~VideoOverlayAdapter() = default;
    
    virtual AVFrame* DoOverlay(AVFrame* frame) = 0;
};

} // namespace ffmpegcpp
