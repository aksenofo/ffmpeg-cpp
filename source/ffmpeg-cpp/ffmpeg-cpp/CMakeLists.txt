#
#  Created on: Apr 21, 2023
#      Author: Alexander Ksenofontov
#

include_directories(.)

#---------------------------------------------------------------------------------------------------

add_library(decomp_storage
    AudioFormatConverter.cpp
    FFmpegException.cpp
    OpenCodec.cpp
    CodecDeducer.cpp
    FrameContainer.cpp
    VideoFormatConverter.cpp
)
