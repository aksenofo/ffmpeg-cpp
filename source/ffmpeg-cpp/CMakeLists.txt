#
#  Created on: Sep 8, 2021
#      Author: Alexander Ksenofontov
#

#cmake_minimum_required(VERSION 3.14.4)
cmake_minimum_required(VERSION 3.12.4)

project(nhsm)

SET(ROOT_PROJECT ${PROJECT_SOURCE_DIR})

if(NOT DEFINED ENV{LIB_MNT})
    message(FATAL_ERROR "Variable LIB_MNT is not defined. All libraries and extra tools  will not be accessable." )
endif()

#SET(PROJECT_LIBS /home/aksenofo/PROJECT/lib_mnt/)

SET(PROJECT_LIBS "$ENV{LIB_MNT}/")

SET(PROJECT_3TH ${PROJECT_SOURCE_DIR}/3th-src)

SET(PROJECT_3TH_MODULE ${PROJECT_SOURCE_DIR}/3th-submodule)

SET(PROJECT_UTIL ${PROJECT_SOURCE_DIR}/util)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD 11)

#---------------------------------------------------------------------------------------------------
INCLUDE (${ROOT_PROJECT}/CMake/start.cmake)
#---------------------------------------------------------------------------------------------------

message( "LIB_MNT            :" $ENV{LIB_MNT} )
message( "3th-src            :" $PROJECT_3TH )
message( "CMAKE_CXX_STANDARD :" $CMAKE_CXX_STANDARD )

include_directories(.)

add_subdirectory(app)
add_subdirectory(bootenv)

add_subdirectory(3th-src)
