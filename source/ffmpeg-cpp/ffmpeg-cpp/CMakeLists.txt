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
     "Frame Sinks/*.cpp"
     "Info/*.cpp"
     "Muxing/*.cpp"
     "Sources/*.cpp"
     "codecs/*.cpp"
)

add_library(decomp_storage
    ${all_files}
)
