cmake_minimum_required(VERSION 3.24)

project(
    MacroRecorder
    VERSION 0.0.1
    DESCRIPTION "Can we actually do this?"
    LANGUAGES CXX)
add_executable(MacroRecorder src/main.cpp)
target_compile_features(MacroRecorder PRIVATE cxx_std_20)