#
#  Created on: Apr 21, 2023
#      Author: Alexander Ksenofontov
#

include_directories(.)

#---------------------------------------------------------------------------------------------------
file(GLOB all_files
     "*.cpp"
     "Codecs/*.cpp"
     "Demuxing/*.cpp"
     "Frame_Sinks/*.cpp"
     "Info/*.cpp"
     "Muxing/*.cpp"
     "Sources/*.cpp"
     "codecs/*.cpp"
)

add_library(ffmpegcpp
    ${all_files}
)
