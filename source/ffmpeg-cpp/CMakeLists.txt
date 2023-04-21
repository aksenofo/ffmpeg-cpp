#
#  Created on: Apr 21, 2023
#      Author: Alexander Ksenofontov
#

cmake_minimum_required(VERSION 3.12.4)

project(ffmpeg-cpp)

set(CMAKE_CXX_STANDARD 17)

#FIXIT: temp using 
include_directories(/home/aksenofo/PROJECT/mnt/FFMPEG/bld/dist/include)

add_subdirectory(ffmpeg-cpp)

include_directories(ffmpeg-cpp)

set(ffmpeglib 
    /home/aksenofo/PROJECT/mnt/FFMPEG/bld/dist/lib/libavcodec.a
    /home/aksenofo/PROJECT/mnt/FFMPEG/bld/dist/lib/libavfilter.a
    /home/aksenofo/PROJECT/mnt/FFMPEG/bld/dist/lib/libavutil.a
    /home/aksenofo/PROJECT/mnt/FFMPEG/bld/dist/lib/libswscale.a
    /home/aksenofo/PROJECT/mnt/FFMPEG/bld/dist/lib/libavdevice.a
    /home/aksenofo/PROJECT/mnt/FFMPEG/bld/dist/lib/libavformat.a
    /home/aksenofo/PROJECT/mnt/FFMPEG/bld/dist/lib/libswresample.a

    /home/aksenofo/PROJECT/mnt/FFMPEG/bld/dist/lib/libavcodec.a
    /home/aksenofo/PROJECT/mnt/FFMPEG/bld/dist/lib/libavfilter.a
    /home/aksenofo/PROJECT/mnt/FFMPEG/bld/dist/lib/libavutil.a
    /home/aksenofo/PROJECT/mnt/FFMPEG/bld/dist/lib/libswscale.a
    /home/aksenofo/PROJECT/mnt/FFMPEG/bld/dist/lib/libavdevice.a
    /home/aksenofo/PROJECT/mnt/FFMPEG/bld/dist/lib/libavformat.a
    /home/aksenofo/PROJECT/mnt/FFMPEG/bld/dist/lib/libswresample.a
)

function (build_proj name)
    set(libs
        ffmpegcpp
        ${ffmpeglib}
        pthread
        z
        lzma
        bz2
    )

    file(GLOB files "${name}/*.cpp" )
    add_executable(${name} ${files})
    target_link_libraries(${name} ${libs})
endfunction()

build_proj(decode_audio)
build_proj(decode_video)
build_proj(demo)
build_proj(difference)
build_proj(encode_audio)
build_proj(encode_video)
build_proj(filtering_audio)
build_proj(filtering_video)
build_proj(print_info)
build_proj(remuxing)
#build_proj(simple_interface)
#build_proj(simple_interface_demo)

