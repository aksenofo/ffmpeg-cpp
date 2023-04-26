#pragma once

#include "ffmpeg.h"

#include <functional>
#include <vector>

namespace ffmpegcpp
{
class CodecDeducer
{
    constexpr static int NoTypeFilter = AVMEDIA_TYPE_UNKNOWN - 1; 
public:
    static AVCodec* DeduceEncoderFromFilename(const char* fileName);

    static AVCodec* DeduceEncoder(AVCodecID codecId);
    static AVCodec* DeduceEncoder(const char* codecName);
    static std::vector<const AVCodec*> DeduceEncoderList(const AVMediaType& type = static_cast<AVMediaType>(NoTypeFilter));

    static AVCodec* DeduceDecoder(AVCodecID codecId);
    static AVCodec* DeduceDecoder(const char* codecName);
    static std::vector<const AVCodec*> DeduceDecoderList(const AVMediaType& type = static_cast<AVMediaType>(NoTypeFilter));

private:
    static std::vector<const AVCodec*> GatherList(const AVMediaType& type, std::function<bool(const AVCodec* c)> is);
};

} // namespace ffmpegcpp
