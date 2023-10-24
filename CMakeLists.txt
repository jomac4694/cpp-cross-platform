cmake_minimum_required(VERSION 3.24)

project(
    MacroRecorder
    VERSION 0.0.1
    DESCRIPTION "Simple application for recording and replaying mouse/key input"
    LANGUAGES CXX)

set(HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/")
set(SOURCES 
    src/main.cpp 
    src/Robot.cpp
    src/Playback.cpp)
if (WIN32)
    list(APPEND SOURCES src/WindowsRobotImpl.cpp src/WindowsGlobalListener.cpp)
    list(APPEND HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/Win32")
elseif(APPLE)
    list(APPEND SOURCES src/MacRobotImpl.cpp)
    set(CMAKE_OSX_ARCHITECTURES "arm64")
endif()
include_directories(${HEADERS})
add_executable(MacroRecorder ${SOURCES})
#target_include_directories(MacroRecorder PUBLIC ${HEADERS}) is this even needed?
if(APPLE)
    target_link_libraries(MacroRecorder "-framework ApplicationServices")
    target_link_libraries(MacroRecorder "-framework CoreFoundation")
endif()
target_compile_features(MacroRecorder PRIVATE cxx_std_20)
