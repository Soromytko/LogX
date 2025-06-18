cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

project(LogX)

set(BINARY_NAME logx)
set(CMAKE_CXX_STANDARD 23)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_EXTENSIONS OFF) 

set(SOURCE_FILES
    src/Logger.cpp
)

set(HEADER_FILES
    include/logx/defines.h
    include/logx/Logger.h
)

include_directories(include)
add_library(${BINARY_NAME} STATIC ${SOURCE_FILES} ${HEADER_FILES})
#target_compile_features(${BINARY_NAME} PRIVATE cxx_std_20)
target_include_directories(${BINARY_NAME} PUBLIC include)
