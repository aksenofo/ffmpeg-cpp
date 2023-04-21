#
#  Created on: Apr 21, 2023
#      Author: Alexander Ksenofontov
#

cmake_minimum_required(VERSION 3.12.4)

project(ffmpeg-cpp)

set(CMAKE_CXX_STANDARD 17)

set (FFMPEG_ROOT /home/aksenofo/PROJECT/mnt/FFMPEG/bld/dist)

include_directories(${FFMPEG_ROOT}/include)

add_subdirectory(ffmpeg-cpp)

include_directories(ffmpeg-cpp)

set(ffmpeglib 
    ${FFMPEG_ROOT}/lib/libavcodec.a
    ${FFMPEG_ROOT}/lib/libavfilter.a
    ${FFMPEG_ROOT}/lib/libavutil.a
    ${FFMPEG_ROOT}/lib/libswscale.a
    ${FFMPEG_ROOT}/lib/libavdevice.a
    ${FFMPEG_ROOT}/lib/libavformat.a
    ${FFMPEG_ROOT}/lib/libswresample.a

    ${FFMPEG_ROOT}/lib/libavcodec.a
    ${FFMPEG_ROOT}/lib/libavfilter.a
    ${FFMPEG_ROOT}/lib/libavutil.a
    ${FFMPEG_ROOT}/lib/libswscale.a
    ${FFMPEG_ROOT}/lib/libavdevice.a
    ${FFMPEG_ROOT}/lib/libavformat.a
    ${FFMPEG_ROOT}/lib/libswresample.a

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

