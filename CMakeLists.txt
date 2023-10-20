cmake_minimum_required(VERSION 3.24)

project(
    MacroRecorder
    VERSION 0.0.1
    DESCRIPTION "Can we actually do this?"
    LANGUAGES CXX)
set(CMAKE_OSX_ARCHITECTURES "arm64")
set(HEADERS include/Input.h include/RobotImpl.h)
set(SOURCES src/main.cpp src/Robot.cpp)
if (WIN32)
    list(APPEND SOURCES src/WindowsRobotImpl.cpp)
elseif(APPLE)
    list(APPEND SOURCES src/MacRobotImpl.cpp)
endif()
include_directories(${HEADERS})
add_executable(MacroRecorder ${SOURCES})
target_include_directories(MacroRecorder PUBLIC ${HEADERS})
target_link_libraries(MacroRecorder "-framework ApplicationServices")
target_link_libraries(MacroRecorder "-framework CoreFoundation")
target_compile_features(MacroRecorder PRIVATE cxx_std_20)