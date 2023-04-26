#include "CodecDeducer.h"

#include "FFmpegException.h"

using namespace std;

namespace ffmpegcpp
{
AVCodec* CodecDeducer::DeduceEncoder(const char* codecName)
{
    AVCodec* codec = avcodec_find_encoder_by_name(codecName);
    if (!codec) {
        throw FFmpegException("Codec " + string(codecName) + " not found");
    }
    return codec;
}

AVCodec* CodecDeducer::DeduceEncoder(AVCodecID codecId)
{
    AVCodec* codec = avcodec_find_encoder(codecId);
    if (!codec) {
        throw FFmpegException("Codec with id " + to_string((int)codecId) + " not found");
    }
    return codec;
}


std::vector<const AVCodec*> CodecDeducer::DeduceEncoderList(const AVMediaType& type)
{
    return GatherList(type, av_codec_is_encoder);
}

std::vector<const AVCodec*> CodecDeducer::DeduceDecoderList(const AVMediaType& type)
{
    return GatherList(type, av_codec_is_decoder);
}

std::vector<const AVCodec*> CodecDeducer::GatherList(const AVMediaType& type, std::function<bool(const AVCodec* c)> is)
{
    std::vector<const AVCodec*> en;
    void *i = 0;
    const AVCodec* c = nullptr;
    while ((c = av_codec_iterate(&i))) {
        if (is(c) && (type == NoTypeFilter || type == c->type))
            en.push_back(c);
    }
    return en;
}


AVCodec* CodecDeducer::DeduceDecoder(const char* codecName)
{
    AVCodec* codec = avcodec_find_decoder_by_name(codecName);
    if (!codec) {
        throw FFmpegException("Codec " + string(codecName) + " not found");
    }
    return codec;
}

AVCodec* CodecDeducer::DeduceDecoder(AVCodecID codecId)
{
    if (codecId == AV_CODEC_ID_NONE)
        return nullptr;
    AVCodec* codec = avcodec_find_decoder(codecId);
    if (!codec) {
        throw FFmpegException("Codec with id " + to_string((int)codecId) + " not found");
    }
    return codec;
}

AVCodec* CodecDeducer::DeduceEncoderFromFilename(const char* fileName)
{
    throw FFmpegException("Not implemented yet");
}
} // namespace ffmpegcpp
