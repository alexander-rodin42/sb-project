cmake_minimum_required(VERSION 3.20)
project(1_imitation_audio_player)

set(CMAKE_CXX_STANDARD 14)

add_executable(1_imitation_audio_player src/main.cpp
        include/Track.h src/Track.cpp
        include/AudioPlayer.h src/AudioPlayer.cpp)

target_include_directories(1_imitation_audio_player PUBLIC include)
