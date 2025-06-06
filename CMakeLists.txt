cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

project(LogX)

set(BINARY_NAME logx)
set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
    src/CLogger.cpp
    src/WLogger.cpp
)

set(HEADER_FILES
    include/logx/defines.h
    include/logx/AbstractLogger.h
    include/logx/CLogger.h
    include/logx/WLogger.h
)

include_directories(include)
add_library(${BINARY_NAME} STATIC ${SOURCE_FILES} ${HEADER_FILES})
target_include_directories(${BINARY_NAME} PUBLIC include)
