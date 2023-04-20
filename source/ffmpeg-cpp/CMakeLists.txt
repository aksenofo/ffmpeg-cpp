#
#  Created on: Apr 21, 2023
#      Author: Alexander Ksenofontov
#

cmake_minimum_required(VERSION 3.12.4)

project(ffmpeg-cpp)

set(CMAKE_CXX_STANDARD 17)

#FIXIT: temp using 
include_directories(/home/aksenofo/PROJECT/mnt/FFMPEG/bld/dist/include)

#add_definitions(-D _GLIBCXX_USE_NOEXCEPT)


add_subdirectory(ffmpeg-cpp)
